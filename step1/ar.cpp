#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv) {
    cv::VideoCapture cap(0);
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    cv::Mat image;

    for (;;) {
        cap >> image;
        cv::imshow("image", image);
        cv::waitKey(1);
    }

    return 0;
}
