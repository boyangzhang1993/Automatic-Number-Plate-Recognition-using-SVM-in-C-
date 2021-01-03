//
//  DetectRegions.hpp
//  LearnOpenCV
//
//  Created by Boyang Zhang on 1/3/21.
//

#ifndef DetectRegions_hpp
#define DetectRegions_hpp

#include <stdio.h>
#include <vector>
#include "Plate.hpp"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class DetectRegions{
    public:
        DetectRegions();
        string filename;
        void setFilename(string f);
        bool saveRegions;
        bool showSteps;
        vector<Plate> run(Mat input);
    private:
        vector<Plate> segment(Mat input);
        bool verifySizes(RotatedRect mr);
        Mat histeq(Mat in);
};




#endif /* DetectRegions_hpp */
