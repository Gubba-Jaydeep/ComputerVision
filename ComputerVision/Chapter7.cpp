////
////  Chapter7.cpp
////  ComputerVision
////
////  Created by Jaydeep Gubba on 16/01/22.
////
//
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//
//
//
//void getContours(Mat imgDil, Mat img){
//
//    //contour is like this {{Point(20,30),Point(50,60)},{Point(20,30),Point(50,60)},{Point(20,30),Point(50,60)}}
//
//    vector<vector<Point>> contours;
//    vector<Vec4i> hierarchy;
//
//
//    // first we find the contour(means outline) points from dilated image(basically creates points on lined formed by dilation and seperates them into different vectors based on shape.. check how it does that)
//    // A rectangle also may have 200-500 points, need notalways be only 4 points
//    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//    vector<vector<Point>> conPoly(contours.size());
//    vector<Rect> boundRect(contours.size());
//
//
//    for(int i=0; i<contours.size(); i++){
//        double area = contourArea(contours[i]);
//        cout << area << endl;
//
//        
//        string objectType;
//
//        if (area>1000){
//            double peri = arcLength(contours[i], true);
//            //approximates a curve/polygon with another curve/polygon with less vertices so that the distance between them is less or equal to the specified precision.(Basically reduces the no of ponts in contour to min, which generally form the edges of a polygon) <http://en.wikipedia.org/wiki/Ramer-Douglas-Peucker_algorithm>
//            approxPolyDP(contours[i], conPoly[i], 0.02*peri, true);
//
//            cout << conPoly[i].size() << "," << contours[i].size() << endl;
//
//            // gives a bounding rectangle around the polygon
//            boundRect[i] =  boundingRect(conPoly[i]);
//
//
//
//            int objCor = (int)conPoly[i].size();
//
//            if (objCor == 3) {objectType = "Tri";}
//            if (objCor == 4) {
//                float aspectRatio = (float)boundRect[i].width/ (float)boundRect[i].height;
//                cout << "aspectRatio: " << aspectRatio << endl;
//                if (aspectRatio>0.95 && aspectRatio<1.05) { objectType="Square"; }
//                else{ objectType = "Rect"; }
//
//            }
//            if (objCor > 4) {objectType = "Circle";}
//
//            drawContours(img, conPoly, i, Scalar(255,0,255),2);
//            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0,255,0), 1);
//            putText(img, objectType, {boundRect[i].x, boundRect[i].y-5}, FONT_HERSHEY_PLAIN,  1, Scalar(0, 69,255), 2);
//
//
//        }
//    }
//}
//
///////////////////  Images  //////////////////////
//int main() {
//
//    string path = "Resources/shapes.png";
//    Mat img = imread(path);
//
//    Mat imgGrey, imgBlur, imgCanny, imgDil, imgErode;
//
//
//    // Preprocessing
//    cvtColor(img, imgGrey, COLOR_BGRA2GRAY);
//    GaussianBlur(imgGrey, imgBlur, Size(3,3), 3, 0);
//    Canny(imgBlur, imgCanny, 25, 75);
//    Mat kernal = getStructuringElement(MORPH_RECT, Size(3,3));
//    dilate(imgCanny, imgDil, kernal);
//
//    getContours(imgDil, img);
//
//
//
//    imshow("Image", img);
////    imshow("Image Gray", imgGrey);
////    imshow("Image Blur", imgBlur);
////    imshow("Image Canny", imgCanny);
////    imshow("Image Dilation", imgDil);
//
//    waitKey(0);
//    return 0;
//}
