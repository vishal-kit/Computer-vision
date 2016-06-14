#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;


class MorphoFeatures
{
//theroshold to produce binary image
	int threshold;
//structuring elements used in corner detection
	Mat cross;
	Mat daimond;
	Mat square;
	Mat x;

public:

}

Mat getEdges(const Mat &image)
{
	//get the gradiant image
	Mat result;
	morphologyEX(image,result,cv::MORPH_GRADIENT,cv::Mat());
	//apply thereshold to the binary image
	applyThreshold(result);
return result;
}

void applyThreshold(cv::Mat & result)
{
	//apply threshold on result
	if(threshold>0)	
		cv::threshold(result,result,threshold,255,cv::THRESH_BINARY);

}

int main(int argc, char ** argv)
{
	if(argc!=2)
	{
		cout<<"input correct arguments\n";
		return -1;
	}
	Mat image;
	image=imread(argv[1],1);
	Mat element5(5,5,CV_8U,Scalar(1));
	Mat closed;
	morphologyEx(image,closed,cv::MORPH_CLOSE,element5);
	namedWindow("Morp",WINDOW_AUTOSIZE);
	imshow("Morp",closed); 
waitKey(0);
return 0;
}
