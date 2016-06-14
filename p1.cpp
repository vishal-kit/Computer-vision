// this program takes an input agrument name of the image to be dispalyed and flips the given image 
// according to the value provided in the flip funtion
// this program is written by Vishal Gaurav
// and saves the resultant image as output.bmp in the present working directory

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc,char** argv)
{
	Mat image;
	if(argc!=2)
	{
		cout<<"Please enter the image name to be read:\n";
	return -1;
	}
	image = imread(argv[1]);
	if(!image.data)
	{
		cout<<"cannot read image\n";
	return -1;
	}
	namedWindow("Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image", image);
	Mat result;
	flip(image,result,0);//+for horizontal
			// 0 vertical]	
			//negative for  both
	namedWindow("Resultant Image",WINDOW_AUTOSIZE);
	imshow("Resultant Image",result);
waitKey(0);
	imwrite("output.bmp",result);
return 0;
}
