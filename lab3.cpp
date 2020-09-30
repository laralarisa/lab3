#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
//#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    VideoCapture cap(0);

    if(!cap.isOpened()) {
        cout << "error" << endl;
        return -1;
    }

    while(true) {
        Mat frame;
        Mat gaussBlur;
        Mat HSV, blue; 
        Mat edges;

        cap >> frame;

        if (frame.empty())
            break;

///
        imshow( "Original", frame);
///
        GaussianBlur(frame, gaussBlur, Size(21, 21), 0, 0);
        imshow("GaussBlur", gaussBlur);
///
        cvtColor(frame, HSV, COLOR_BGR2HSV);
        inRange(HSV, Scalar(101,50,38), Scalar(130,255,255),  blue);  
        imshow(" blue ",  blue);
///

        cvtColor(frame, edges, COLOR_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7, 7), 0, 0);
        Canny(edges, edges, 55, 70);
        imshow("Canny", edges);
///
        if(waitKey(10) == 27)
            break; 
	
    }
   
    cap.release();   
    return 0;
}
