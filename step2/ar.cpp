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
        Mat threshImage;
        threshold(grayImage, threshImage, 128.0, 255.0, THRESH_OTSU);
        cv::imshow("image", threshImage);
    }

    return 0;
}
