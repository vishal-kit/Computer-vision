
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
cout<<"total img size"<< img.total()<<endl;
cout<<"each matrix element"<<img.elemSize()<<endl;
cout <<"value printed by all()"<<img.col(10)<<endl;
        //invert and display the inverted image
//        cvNot(img, img);

//        namedWindow("Inverted",WINDOW_AUTOSIZE);
  //      imshow("Inverted", img);

        waitKey(0);
       
        //cleaning up by default 
        return 0;
}
