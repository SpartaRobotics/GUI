#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int minThreshold = 0;
const int maxThreshold = 100;
Mat img_gray, img_grad, img_canny;
Mat frame;

void cannyTrackbar(int, void*)
{
    Mat mat_frame(frame);

    cvtColor(mat_frame, img_gray, COLOR_BGR2GRAY);
    //blur(img_gray, img_canny, Size(3,3) );
    GaussianBlur(img_gray, img_canny, Size(5,5),0,0 );
    Canny(img_canny, img_canny, 10, minThreshold, 3);

    img_grad = Scalar::all(0);
    frame.copyTo(img_grad, img_canny);
    imshow("Test", img_grad);

}


int main()
{
    VideoCapture cap;
    cap.open(1);

    char c;

    namedWindow("Test", CV_WINDOW_AUTOSIZE);
    createTrackbar("Threshold", "Test", &minThreshold, maxThreshold, cannyTrackbar);

    while(1)
    {
        cap.read(frame);
        
        cannyTrackbar(0,0);

        c = waitKey(33);
        if( c == 'q' || c == 27) break;
    }
    cap.release();
    destroyAllWindows();
    return 0;
}
