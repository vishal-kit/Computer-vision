// please enter the dispaly window name
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main(int argc, char * argv[])
{
	VideoCapture cap(0);//open the default camera
	if(!cap.isOpened())
	{
		cout<<"no camera detected\n";
		return -1;
	}

	namedWindow(argv[1],WINDOW_AUTOSIZE);
	Mat img;
	int ct=0;
	stringstream ss;
	string name = "Photo_0000";
	string type = ".jpg";
	cout<<"in capture"<<endl;
	for(int i=0;i<5;i++)
		{
			cap >> img; //get a new frame from camera
			imshow(argv[1],img);
			ss<<name<<i<<type;
			string filename = ss.str();
			ss.str(" ");
			imwrite(filename, img);
			//if(waitKey(30)>=0)	break;
			waitKey(0);
		}
//waitKey(0);
	
return 0;
}
