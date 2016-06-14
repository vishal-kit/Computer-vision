#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		cout<<"enter valid arguments\n";
	return -1;
	}
	Mat img,er,dl;

	img=imread(argv[1]);
	namedWindow("Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image",img);


	erode(img,er,Mat());
	namedWindow("erroded Image", WINDOW_AUTOSIZE);
	imshow("erroded Image",er);

	dilate(img,dl,Mat());
	namedWindow("dailated Image", WINDOW_AUTOSIZE);
	imshow("dailated Image",dl);

	imshow("Original image", img);



waitKey(0);
return 0;
}
