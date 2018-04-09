#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int min_3 = 106;
int const max_3 = 192;

int min_4 = 180;
int const max_4 = 360;

int min_5 = 110;
int const max_5 = 215;

int lowThreshold = -10;
int const max_lowThreshold = 100;

void Threshold_3(int, void*)
{
	int temp = min_3 - 92;
}

void Threshold_4(int, void*)
{
	int temp = min_4;
}

void Threshold_5(int, void*)
{
	int temp = min_5 + 105;
}

void Threshold_6(int, void*)
{

}

int main()
{
	namedWindow("Window", CV_WINDOW_AUTOSIZE);
	createTrackbar( "Servo 3:", "Window", &min_3, max_3, Threshold_3);
	createTrackbar( "Servo 4:", "Window", &min_4, max_4, Threshold_4);
	createTrackbar( "Servo 5:", "Window", &min_5, max_5, Threshold_5);
	createTrackbar( "Servo 6:", "Window", &lowThreshold, max_lowThreshold, Threshold_6);

	char c;

	while(1)
	{
		c = waitKey(33);
		if( c == 'q') break;
	}

	destroyAllWindows();
	return 0;
}
