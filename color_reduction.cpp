#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void colorReduce(Mat & im, int div)
{
	int nl	=	im.rows;
	int nc	=	im.cols * im.channels();
	
	for(int j=0; j<nl; j++)
	{
		uchar* data = im.ptr<uchar> (j);
		for(int i=0;i<nc;i++)
		{
			data[i]	= (data[i] / (div*div)) + (div/2);	
		}
	}
}

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		cout << "enter the file name\n";
	return -1;
	}
	Mat img;//result;
	img = imread(argv[1]);
	namedWindow("Original", WINDOW_AUTOSIZE);
	imshow("Original", img);


	colorReduce(img,6);
	//namedWindow("reduced", WINDOW_AUTOSIZE);
	imshow("Original", img);

	waitKey(0);
return 0;
}
