//
//  Chapter6.cpp
//  ComputerVision
//
//  Created by Jaydeep Gubba on 16/01/22.
//

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;



/////////////////  Color detection  //////////////////////
//Mat imgHSV,mask;
//int hmin=0, smin=110, vmin=153;
//int hmax=19, smax=240, vmax=255;
//
//
//int main() {
//    string path = "Resources/lambo.png";
//    Mat img = imread(path);
//    cvtColor(img, imgHSV, COLOR_BGR2HSV);
//
//    namedWindow("Trackbars");
//    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
//    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
//    createTrackbar("Sat Min", "Trackbars", &smin, 255);
//    createTrackbar("Sat Max", "Trackbars", &smax, 255);
//    createTrackbar("Val Min", "Trackbars", &vmin, 255);
//    createTrackbar("Val Max", "Trackbars", &vmax, 255);
//
//    while (true) {
//        Scalar lower(hmin, smin, vmin);
//        Scalar upper(hmax, smax, vmax);
//
//        inRange(imgHSV, lower, upper, mask);
//
//        imshow("Image", img);
//        imshow("Image HSV", imgHSV);
//        imshow("Image Mask", mask);
//
//        waitKey(1);
//    }
//
//
//
//
//    return 0;
//}
