#include<highgui.h>

int main(int argc,char** argv)
{
char c;
	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
	CvCapture * capture = cvCreateFileCapture(argv[1]);
	IplImage* frame;
	while (1)
	{
		frame = cvQueryFrame(capture);
		if(!frame) break;
		cvShowImage("Eample2", frame);
	 c = cvWaitKey(0);
		if(c==27) break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2");
}
