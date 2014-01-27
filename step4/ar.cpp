#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char** argv) {
    VideoCapture cap(0);
    if(!cap.isOpened())  // check if we succeeded
        return -1;

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
        vector<vector<Point> > squares;
        for (auto contour : contours) {
            vector<Point> approx;
            approxPolyDP(contour, approx, arcLength(Mat(contour), true)*0.02, true);
            if( approx.size() == 4 &&
                fabs(contourArea(Mat(approx))) > 1000 &&
                isContourConvex(Mat(approx)) )
            {
                squares.push_back(approx);
            }
        }
        drawContours(image, squares, -1, color);
        cv::imshow("image", image);
    }

    return 0;
}
