//
//  Plate.hpp
//  LearnOpenCV
//
//  Created by Boyang Zhang on 1/3/21.
//

#ifndef Plate_hpp
#define Plate_hpp

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

class Plate{
    public:
        Plate();
        Plate(Mat img, Rect pos);
        string str();
        Rect position;
        Mat plateImg;
        vector<char> chars;
        vector<Rect> charsPos;
};






#endif /* Plate_hpp */
