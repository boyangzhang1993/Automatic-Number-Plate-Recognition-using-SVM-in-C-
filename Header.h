//
//  Header.h
//  LearnOpenCV
//
//  Created by Boyang Zhang on 1/2/21.
//
#include <string.h>
#include <vector>
#include <highgui.h>
#include <cvaux.h>

using namespace std;
using namespace cv;
#ifndef Header_h
#define Header_h
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

#endif /* Header_h */
