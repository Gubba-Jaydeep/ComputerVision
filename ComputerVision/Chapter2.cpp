//
//  Chapter1.cpp
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



/////////////////  Important Functions  //////////////////////
 int main() {

     string path = "Resources/test.png";
     Mat img = imread(path);
     Mat imgGrey, imgBlur, imgCanny, imgDil, imgErode;
     
     cvtColor(img, imgGrey, COLOR_BGRA2GRAY);
     GaussianBlur(img, imgBlur, Size(3,3), 3, 0);
     Canny(imgBlur, imgCanny, 25, 75);
     
     Mat kernal = getStructuringElement(MORPH_RECT, Size(3,3));
     dilate(imgCanny, imgDil, kernal);
     erode(imgDil, imgErode, kernal);
     
     imshow("Image", img);
     imshow("Image Gray", imgGrey);
     imshow("Image Blur", imgBlur);
     imshow("Image Canny", imgCanny);
     imshow("Image Dilation", imgDil);
     imshow("Image Erode", imgErode);
     waitKey(0);
     return 0;
 }


