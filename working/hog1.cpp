// Example of how to use the OpenCV Particle Filter.
// 
// Stolen largely from morethantechnical.com's nice mouse_kalman project.
//

#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/legacy/legacy.hpp>

using namespace std;

#define drawCross( center, color, d )                  \
  line( img, cv::Point( center.x - d, center.y - d ),           \
    cv::Point( center.x + d, center.y + d ), color, 2, CV_AA, 0);   \
  line( img, cv::Point( center.x + d, center.y - d ),           \
    cv::Point( center.x - d, center.y + d ), color, 2, CV_AA, 0 )

struct mouse_info_struct { int x,y; };
struct mouse_info_struct mouse_info = {-1,-1}, last_mouse;

vector<cv::Point> mouseV, particleV;
int counter = -1;

// Define this to proceed one click at a time.
//#define CLICK 1
#define PLOT_PARTICLES 1

void on_mouse(int event, int x, int y, int flags, void* param) {
#ifdef CLICK
  if (event == CV_EVENT_LBUTTONUP) 
#endif
  {
    last_mouse = mouse_info;
    mouse_info.x = x;
    mouse_info.y = y;
    counter = 0;
  }
}

int main (int argc, char * const argv[]) {
  cv::Mat img(650, 650, CV_8UC3);
  char code = (char)-1;
//img = cv::imread(argv[1],1);
  cv::namedWindow("mouse particle");
  cv::setMouseCallback("mouse particle", on_mouse, 0);

  cv::Mat_<float> measurement(2,1); 
  measurement.setTo(cv::Scalar(0));

  int dim = 2;
  int nParticles = 25;
  float xRange = 650.0;
  float yRange = 650.0;

  float minRange[] = { 0, 0 };
  float maxRange[] = { xRange, yRange };
  CvMat LB, UB;
  cvInitMatHeader(&LB, 2, 1, CV_32FC1, minRange);
  cvInitMatHeader(&UB, 2, 1, CV_32FC1, maxRange);

  CvConDensation* condens = cvCreateConDensation(dim, dim, nParticles);

  cvConDensInitSampleSet(condens, &LB, &UB);

  // The OpenCV documentation doesn't tell you to initialize this
  // transition matrix, but you have to do it.  For this 2D example, 
  // we're just using a 2x2 identity matrix.  I'm sure there's a slicker 
  // way to do this, left as an exercise for the reader.
  condens->DynamMatr[0] = 1.0;
  condens->DynamMatr[1] = 0.0;
  condens->DynamMatr[2] = 0.0;
  condens->DynamMatr[3] = 1.0;

  for(;;) {

    if (mouse_info.x < 0 || mouse_info.y < 0) {
      imshow("mouse particle", img);
      cv::waitKey(30);
      continue;
    }

    mouseV.clear();
    particleV.clear();

    for(;;) {
      code = (char)cv::waitKey(100);

      if( code > 0 )
    break;

#ifdef CLICK
      if (counter++ > 0) {
    continue;
      } 
#endif

      measurement(0) = mouse_info.x;
      measurement(1) = mouse_info.y;

      cv::Point measPt(measurement(0),measurement(1));
      mouseV.push_back(measPt);

      // Clear screen
      img = cv::Scalar::all(100);

      for (int i = 0; i < condens->SamplesNum; i++) {

    float diffX = (measurement(0) - condens->flSamples[i][0])/xRange;
    float diffY = (measurement(1) - condens->flSamples[i][1])/yRange;

    condens->flConfidence[i] = 1.0 / (sqrt(diffX * diffX + diffY * diffY));

    // plot particles
#ifdef PLOT_PARTICLES
    cv::Point partPt(condens->flSamples[i][0], condens->flSamples[i][1]);
    drawCross(partPt , cv::Scalar(255,0,255), 2);
#endif

      }

      cvConDensUpdateByTime(condens);

      cv::Point statePt(condens->State[0], condens->State[1]);
      particleV.push_back(statePt);

      // plot points
      drawCross( statePt, cv::Scalar(255,255,255), 5 );
      drawCross( measPt, cv::Scalar(0,0,255), 5 );

      for (int i = 0; i < mouseV.size() - 1; i++) {
    line(img, mouseV[i], mouseV[i+1], cv::Scalar(255,255,0), 1);
      }
      for (int i = 0; i < particleV.size() - 1; i++) {
    line(img, particleV[i], particleV[i+1], cv::Scalar(0,255,0), 1);
      }

      imshow( "mouse particle", img );
    }

    if( code == 27 || code == 'q' || code == 'Q' )
      break;
  }

  return 0;
}
