//please enter the image name
#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char * argv[])
{
	if(argc!=2)
	{
		return -1;
	}
	Mat img;
	img = imread(argv[1]);

	if(!img.data)
	{
		cout<<"No image data\n";
		return -1;
	}
//cout <<img[0]<<endl;
	cout<<"first pixel="<< img.at<double>(0,0) <<endl;
	cout<<"image dim="<< img.dims <<endl;
	cout<<"height="<<img.size().height<<endl;
	cout<<"width="<<img.size().width<<endl;
// what is the need to create the namedWindow
	namedWindow("Display Window",WINDOW_AUTOSIZE);
	imshow("Display Window",img);
Mat img1;
	cv::blur(img,img1,cv::Size(3,3));
	namedWindow("Resultant Window", WINDOW_AUTOSIZE);
	imshow("Resultant Window",WINDOW_AUTOSIZE);
	waitKey(0);
	return 0;


}
