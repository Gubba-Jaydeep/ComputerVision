//
//  Project2.cpp
//  ComputerVision
//
//  Created by Jaydeep Gubba on 17/01/22.
//

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;



/////////////////  Images  //////////////////////

Point getContours(Mat imgDil){

    //contour is like this {{Point(20,30),Point(50,60)},{Point(20,30),Point(50,60)},{Point(20,30),Point(50,60)}}

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;


    // first we find the contour(means outline) points from dilated image(basically creates points on lined formed by dilation and seperates them into different vectors based on shape.. check how it does that)
    // A rectangle also may have 200-500 points, need notalways be only 4 points
    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());

    // will return 0,0 if no contors r found
    Point myPoint(0,0);


    for(int i=0; i<contours.size(); i++){
        double area = contourArea(contours[i]);
        cout << area << endl;

        string objectType;

        if (area>1000){
            double peri = arcLength(contours[i], true);
            //approximates a curve/polygon with another curve/polygon with less vertices so that the distance between them is less or equal to the specified precision.(Basically reduces the no of ponts in contour to min, which generally form the edges of a polygon) <http://en.wikipedia.org/wiki/Ramer-Douglas-Peucker_algorithm>
            approxPolyDP(contours[i], conPoly[i], 0.02*peri, true);

            cout << conPoly[i].size() << "," << contours[i].size() << endl;

            // gives a bounding rectangle around the polygon
            boundRect[i] =  boundingRect(conPoly[i]);
            myPoint.x = boundRect[i].x + boundRect[i].width/2;
            myPoint.y = boundRect[i].y;


            drawContours(img, conPoly, i, Scalar(255,0,255),2);
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0,255,0), 1);

        }
    }
    return myPoint;
}

int main() {
    
    string path = "Resources/paper.jpg";
    Mat img = imread(path);
    
    getContour(img);
    
    
    
    imshow("Image", img);
    waitKey(0);
    return 0;
}
