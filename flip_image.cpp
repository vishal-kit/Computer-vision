#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char ** argv)
{
	if(!argc)
	{
		cout	<<	"enter the file name"	<< 	endl;
	return -1;
	}
	Mat_<Vec3b> img,result;
	img	=	imread(argv[1]);
	flip(img,result,1);
	namedWindow("DIS",WINDOW_AUTOSIZE);
	imshow("DIS",img);
	namedWindow("Flipped", WINDOW_AUTOSIZE);
	imshow("Flipped",result);
	waitKey(0);
return 0;
}
