/*
this program takes file name as input argument and applies the mean filter to the image 
and displays the output
*/

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(int argc,char**  argv)
{
	if(argc!=2)
	{
		cout<<"Please enter vail input argv:\n";
	return -1;
	}
	Mat img;
	img=imread(argv[1]);
	namedWindow("Original Image",WINDOW_AUTOSIZE);
	imshow("Original Image", img);
	Mat result;
	medianBlur( img, result, 3);

	namedWindow("Mean Blur", WINDOW_AUTOSIZE);
	imshow("Mean Blur", result);
waitKey(0);
return 0;
}
