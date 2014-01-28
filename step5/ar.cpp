#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    VideoCapture cap(0);
    if(!cap.isOpened())  // check if we succeeded
        return -1;
    
    FileStorage fs("out_camera_data.xml", FileStorage::READ);
    Mat intrinsics, distortion;
    fs["Camera_Matrix"] >> intrinsics;
    fs["Distortion_Coefficients"] >> distortion;
    
    cout << "intrinsics: " << intrinsics.rows << ", " << intrinsics.cols << endl;
    cout << "distortion: " << distortion.rows << ", " << distortion.cols << endl;

    Mat image;

    for (;;) {
        cap >> image;
        Mat grayImage;
        cvtColor(image, grayImage, CV_RGB2GRAY);
        Mat blurredImage;
        blur(grayImage, blurredImage, Size(5, 5));
        Mat threshImage;
        threshold(blurredImage, threshImage, 128.0, 255.0, THRESH_OTSU);
        vector<vector<Point> > contours;
        findContours(threshImage, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
        Scalar color(0, 255, 0);
        vector<Mat> squares;
        for (auto contour : contours) {
            vector<Point> approx;
            approxPolyDP(contour, approx, arcLength(Mat(contour), true)*0.02, true);
            if( approx.size() == 4 &&
                fabs(contourArea(Mat(approx))) > 1000 &&
                isContourConvex(Mat(approx)) )
            {
                Mat squareMat;
                Mat(approx).convertTo(squareMat, CV_32FC3);
                squares.push_back(squareMat);
            }
        }
        
        if (squares.size() > 0) {
            vector<Point3f> objectPoints = {Point3f(-1, -1, 0), Point3f(-1, 1, 0), Point3f(1, 1, 0), Point3f(1, -1, 0)};
            Mat objectPointsMat(objectPoints);
            cout << "objectPointsMat: " << objectPointsMat.rows << ", " << objectPointsMat.cols << endl;
            cout << "squares[0]: " << squares[0].size() << endl;
            Mat rvec;
            Mat tvec;
            solvePnP(objectPointsMat, squares[0], intrinsics, distortion, rvec, tvec);
            
            cout << rvec << endl;
            cout << tvec << endl;
        }

        // drawContours(image, squares, -1, color);
        cv::imshow("image", image);
    }

    return 0;
}
