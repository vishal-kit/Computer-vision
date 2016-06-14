#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;
 
int main() 
{
	VideoCapture stream1(0);   //0 is the id of video device.0 if you have only one camera.
 
	if (!stream1.isOpened()) 
	{ //check if video device has been initialised
		cout << "cannot open camera";
	}
 int i=0;
stringstream ss;
//unconditional loop
	while (true) 
	{
		Mat cameraFrame;
		stream1.read(cameraFrame);
		imshow("cam", cameraFrame);
		//lines to save the capture image
		ss<<"Photo_0000"<<i++<<".bmp";
		string filename = ss.str();
	
		imwrite(filename, cameraFrame);
		ss.str(" ");
		if (i>=10)
		exit(1);
//
		if (waitKey(30) >= 0)
		break;
	
	}
return 0;
}
