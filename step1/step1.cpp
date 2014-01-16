#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#define TRACKING_DURATION (1 * CLOCKS_PER_SEC)
#define MIN_SIZE 150

int main(int argc, char** argv) {
	cv::VideoCapture cap(0);
    if(!cap.isOpened())  // check if we succeeded
        return -1;

	cv::Mat image;

	for (;;) {
		cap >> image;
		cv::imshow("image", image);
	}

	return 0;
}