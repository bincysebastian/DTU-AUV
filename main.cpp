#include <opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{ Mat imgHSV,mask;
int hmin=78,smin=176,vmin=125;
int hmax=82,smax=217,vmax=138;
 string path="sample.jpeg";
 Mat img = imread(path);
cvtColor(img,imgHSV,COLOR_BGR2HSV);
namedWindow("Trackbars",(250,640));
createTrackbar("Hue Min","Trackbars",&hmin,179);
createTrackbar("Hue Max","Trackbars",&hmax,179);
createTrackbar("Sat Min","Trackbars",&smin,255);
createTrackbar("Sat Max","Trackbars",&smax,255);
createTrackbar("Val Min","Trackbars",&vmin,255);
createTrackbar("Val Max","Trackbars",&vmax,255);

while(true)
{
Scalar lower(hmin,smin,vmin);
Scalar upper(hmax,smax,vmax);
 inRange(imgHSV,lower,upper,mask);
 imshow("Image",img);
 imshow("Image hsv",imgHSV);
 imshow("Image mask",mask);
 waitKey(1);
}
 return 0;
}
