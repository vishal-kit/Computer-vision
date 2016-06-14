#include <opencv2/opencv.hpp>

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/** Function Headers */
void detectAndDisplay( Mat frame );

/** Global variables */
String human_cascade_name = "haarcascade_fullbody.xml";
CascadeClassifier human_cascade;
String window_name = "Human detection";

/** @function main */
int main( int argc, char ** argv )
{
	namedWindow(window_name,CV_WINDOW_AUTOSIZE);
    //VideoCapture capture;
	CvCapture * capture = cvCreateFileCapture(argv[1]);
	Mat frame;

    //-- 1. Load the cascades

    if( !human_cascade.load( human_cascade_name ) ){ printf("--(!)Error loading eyes cascade\n"); return -1; };

    //-- 2. Read the video stream

	while(1)
    	{
		frame = cvQueryFrame(capture);
		/*if(!capture->isopen()) 
        	{
        	    printf(" --(!) No captured frame -- Break!");
        	    break;
        	}*/

        //-- 3. Apply the classifier to the frame
        	detectAndDisplay( frame );

        	int c = waitKey(10);
        	if( (char)c == 27 ) { break; } // escape
    	}
return 0;
}

/** @function detectAndDisplay */
void detectAndDisplay(  Mat frame )
{
    std::vector<Rect> human;
    Mat frame_gray;

    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    human_cascade.detectMultiScale( frame_gray, human, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );

    for ( size_t i = 0; i < human.size(); i++ )
    {
        Point center( human[i].x + human[i].width/2, human[i].y + human[i].height/2 );
       	ellipse( frame, center, Size( human[i].width/2, human[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
	//rectangle(frame,center, Size( human[i].width/2, human[i].height/2 ),Scalar(255,0,255),4,8,0);
      
    }
    //-- Show what you got
    imshow( window_name, frame );
}
