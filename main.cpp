//
//  main.cpp
//  LearnOpenCV
//
//  Created by Boyang Zhang on 12/31/20.
//

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/features2d.hpp>

using namespace cv;
using namespace std;

bool verifySizes(RotatedRect candidate ){

  float error=0.4;
//Spain car plate size: 52x11 aspect 4,7272
  const float aspect=4.7272;
//Set a min and max area. All other patches are discarded
  int min= 15*aspect*15; // minimum area
  int max= 125*aspect*125; // maximum area
//Get only patches that match to a respect ratio.
  float rmin= aspect-aspect*error;
  float rmax= aspect+aspect*error;

  int area= candidate.size.height * candidate.size.width;
  float r= (float)candidate.size.width / (float)candidate.size.height;
  if(r<1)
  r= 1/r;

  if(( area < min || area > max ) || ( r < rmin || r > rmax )){
    return false;
  }else{
  return true;
  }
}


int main()
{
    std::string image_path = samples::findFile("image1.jpg");
    Mat img = imread(image_path, IMREAD_COLOR);
    if(img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    Mat img_gray;
    Mat input = imread(image_path, IMREAD_COLOR);
    cvtColor(input, img_gray, cv::COLOR_BGR2GRAY);
    //Find vertical lines. Car plates have high density of vertical lines
    Mat img_sobel;
    Sobel(img_gray, img_sobel, CV_8U, 1, 0, 3, 1, 0);
    //threshold image
    Mat img_threshold;
    threshold(img_sobel, img_threshold, 0, 255, cv::THRESH_OTSU+cv::THRESH_BINARY);
    Mat element = getStructuringElement(MORPH_RECT, Size(17, 3));
    morphologyEx(img_threshold, img_threshold, cv::MORPH_CLOSE, element);
    //Find contours of possibles plates
    vector< vector< Point> > contours;
    findContours(img_threshold,
                contours,           // a vector of contours
                cv::RETR_EXTERNAL,   // retrieve the external contours
                cv::CHAIN_APPROX_NONE); // all pixels of each contour
    
    //Start to iterate to each contour found
    vector<vector<Point> >::iterator itc= contours.begin();
    vector<RotatedRect> rects;

    //Remove patch that has  no inside limits of aspect ratio and area.
    
    while (itc!=contours.end()) {
    //Create bounding rect of object
      RotatedRect mr= minAreaRect(Mat(*itc));
      if( !verifySizes(mr)){
        itc= contours.erase(itc);
      }else{
      ++itc;
      rects.push_back(mr);
      }
    }
    
    for(int i=0; i< rects.size(); i++){
    //For better rect cropping for each possible box
    //Make floodfill algorithm because the plate has white background
    //And then we can retrieve more clearly the contour box
    circle(result, rects[i].center, 3, Scalar(0,255,0), -1);
    //get the min size between width and height
    float minSize=(rects[i].size.width < rects[i].size.height)?rects[i].size.width:rects[i].size.height;
    minSize=minSize-minSize*0.5;
    //initialize rand and get 5 points around center for floodfill algorithm
    srand ( time(NULL) );
    //Initialize floodfill parameters and variables
    Mat mask;
    mask.create(input.rows + 2, input.cols + 2, CV_8UC1);
    mask= Scalar::all(0);
    int loDiff = 30;
    int upDiff = 30;
    int connectivity = 4;
    int newMaskVal = 255;
    int NumSeeds = 10;
    Rect ccomp;
    int flags = connectivity + (newMaskVal << 8 ) + cv::FLOODFILL_FIXED_RANGE + cv::FLOODFILL_MASK_ONLY;
    for(int j=0; j<NumSeeds; j++){
      Point seed;
      seed.x=rects[i].center.x+rand()%(int)minSize-(minSize/2);
      seed.y=rects[i].center.y+rand()%(int)minSize-(minSize/2);
      circle(result, seed, 1, Scalar(0,255,255), -1);
      int area = floodFill(input, mask, seed, Scalar(255,0,0), &ccomp,   Scalar(loDiff, loDiff, loDiff), Scalar(upDiff, upDiff, upDiff), flags);
      }
    
    
    /*
    bool DetectRegions::verifySizes(RotatedRect candidate ){

      float error=0.4;
    //Spain car plate size: 52x11 aspect 4,7272
      const float aspect=4.7272;
    //Set a min and max area. All other patches are discarded
      int min= 15*aspect*15; // minimum area
      int max= 125*aspect*125; // maximum area
    //Get only patches that match to a respect ratio.
      float rmin= aspect-aspect*error;
      float rmax= aspect+aspect*error;

      int area= candidate.size.height * candidate.size.width;
      float r= (float)candidate.size.width / (float)candidate.size.height;
      if(r<1)
      r= 1/r;

      if(( area < min || area > max ) || ( r < rmin || r > rmax )){
        return false;
      }else{
      return true;
      }
    }
     */

    
    
    
    
    
    
    /*
    imshow("Display window", input);
    int k = waitKey(0); // Wait for a keystroke in the window
    if(k == 's')
    {
        imwrite("Plates", input);
    }
     */
    return 0;
    
    //convert image to gray

    
    
    
   
    
}

