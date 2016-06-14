//this program takes in input argument the image name
// and applies the bilateralFilter and Box Filter and displays 
//the output

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char ** argv)
{
	if(argc!=2)
	{
		cout<<"enter valid agrguments:\n";
	return -1;
	}	
	Mat img,result,box,lap,sob;
	img=imread(argv[1]);

//displays the original image
	namedWindow("Original Image",WINDOW_AUTOSIZE);
	imshow("Original Image",img);

//bilateral filter is applied and displayed
	bilateralFilter(img,result,9,170,175);
	namedWindow("Bilateral Filter",WINDOW_AUTOSIZE);
	imshow("Bilateral Filter",result);


//boxfilter is applied and result displayed
	boxFilter(img,box,-1,Size(5,5),Point(-1,-1),true,BORDER_DEFAULT);
	namedWindow("Box Filter",WINDOW_AUTOSIZE);
	imshow("Box Filter", box);

//laplacian is applied and result is displayed
//Laplacian(img,lap,-1,3,0,BORDER_DEFAULT);

//sobel filter for edge  extraction
	Sobel(img, sob, CV_8U, 1, 1,3,1,0, BORDER_DEFAULT );
	
	namedWindow("sobel Filter",WINDOW_AUTOSIZE);
	imshow("sobel Filter", sob);
	
	
waitKey(0);
return 0;
}
