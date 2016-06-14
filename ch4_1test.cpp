
#include <opencv2/opencv.hpp>

#include<iostream>

using namespace std;
using namespace cv;

int main()
{
        //display the original image
Mat img;
        img = imread("Lenna.bmp");
        namedWindow("MyWindow",WINDOW_AUTOSIZE);
        imshow("MyWindow", img);

        //invert and display the inverted image

	


        namedWindow("Inverted",WINDOW_AUTOSIZE);
        imshow("Inverted", img);

        waitKey(0);
       
        //cleaning up by default 
        return 0;
}
