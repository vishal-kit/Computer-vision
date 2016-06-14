#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/*void salt(Mat &image, int n)
{
	for(int k=0;k<n;k++)
	{
		int i= rand()%image.cols;
		int j=rand()%image.rows;
		if(image.channels()==1)
		{//gray scale img
			image.at<uchar> (j,i)=255;
		}
		else if (image.channels()==3)
		{//color img
			image.at<Vec3b> (j,i) [0]=255;
			image.at<Vec3b> (j,i) [1]=255;
			image.at<Vec3b> (j,i) [2]=255;
		}
	}
}
*/
int main(int argc, char ** argv)
{
	if(argc!=2)
	{
		cout<<"enter image name\n";
	return -1;
	}
	Mat img;

	img=imread(argv[1]);
int i,j;
	if(!img.data)
	{
		cout<<"cannot read image"<<endl;
	return -1;
	}
	namedWindow("Display Original", WINDOW_AUTOSIZE);
	imshow("Display Original", img);
	Mat img1,img2,img3,img4;

	img2 = img.clone();
	img1 = img.clone();
//	Mat invert;
//	flip(img,invert,1);
//	namedWindow("Flipped", WINDOW_AUTOSIZE);
//	imshow("Flipped",invert);

//	salt(img1,3000);
//	namedWindow("salted img",WINDOW_AUTOSIZE);
//	imshow("salted img",img1);


	cout<<"first pixel="<< img.at<Vec3b> (0,0) [0]<<endl;
	cout<<"pixel value"<<img2(0,0)<<endl; 
/*
	for ( i=1; i<255; i++ )
	{

		for ( j=0; j<255; j++ )
		{

			img3.at<uchar>(i,j) = (int)(( img2.at<uchar>(i-1,j-1) + img2.at<uchar>(i-1,j) + img2.at<uchar>(i-1,j+1) +
				       img2.at<uchar>(i,j-1) + img2.at<uchar>(i,j) + img.at<uchar>(i,j+1) +
				       img2.at<uchar>(i+1,j-1) + img2.at<uchar>(i+1,j) + img2.at<uchar>(i+1,j+1) )/9);

		}

	}

*/
blur(img1,img4,Size(5,5));
	namedWindow("blur",WINDOW_AUTOSIZE);
	imshow("blur",img3);
GaussianBlur(img2,img3,Size(5,5),1.5);
	namedWindow("Gaussian", WINDOW_AUTOSIZE);
	imshow("Gaussian",img4);
//Sobel(img2,sobel1X,CV_8U,1,0,3,0.4,128);
//	namedWindow("sobel horizontal",WINDOW_AUTOSIZE);
//	imshow("sobel horizontal",img2);

	waitKey(0);
return 0;	
}
