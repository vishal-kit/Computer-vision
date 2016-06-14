#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		cout<<"please enter the correct parameters to run\n";
	return -1;
	}
	
	Mat buf;
	namedWindow("Video",WINDOW_AUTOSIZE);
	
char c;
	CvCapture * capture = cvCreateFileCapture(argv[1]);
	//IplImage* frame;
	while (1)
	{
		buf = cvQueryFrame(capture);
		//if(!buf) break;
		imshow("Video",buf);		
		//cvShowImage("Video", buf);
	 	c = cvWaitKey(33);
		if(c==27) break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Video");
return 0;
}
