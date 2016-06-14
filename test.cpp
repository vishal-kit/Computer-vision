#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char ** argv)
{
	if	(argc<2)
	{
		cout<<"enter the file name:"<<endl;
	return -1;
	}
	Mat img;
	img	=	imread(argv[1]);
	Mat_<Vec3b> img1	=	img;
	namedWindow("DISPLAY",WINDOW_AUTOSIZE);
	imshow("DISPLAY",img1);
	cout	<<	"the value of first pixel="	<< 	img1(0,0,0);
	
waitKey(0);
return 0;	
}
