//please enter the image name and display window name
#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char * argv[])
{
	if(argc!=3)
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
	cout<<"image dim="<< img.dims <<endl;
	cout<<"height="<<img.cols<<endl;
	cout<<"width="<<img.rows<<endl;
// what is the need to create the namedWindow
	namedWindow(argv[2],WINDOW_NORMAL);
	imshow(argv[2],img);

	waitKey(0);
	return 0;


}
