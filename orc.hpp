//
//  orc.hpp
//  LearnOpenCV
//
//  Created by Boyang Zhang on 1/3/21.
//

#ifndef orc_hpp
#define orc_hpp

#include <string.h>
#include <vector>

#include "Plate.hpp"
//#include <ml.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


#define HORIZONTAL    1
#define VERTICAL    0

class CharSegment{
public:
    CharSegment();
    CharSegment(Mat i, Rect p);
    Mat img;
    Rect pos;
};

class OCR{
    public:
        bool debug;
        bool saveSegments;
        string filename;
        static const int numCharacters;
        static const char strCharacters[];
        OCR(string trainFile);
        OCR();
        string run(Plate *input);
        int charSize;
        Mat preprocessChar(Mat in);
        int classify(Mat f);
        void train(Mat trainData, Mat trainClasses, int nlayers);
        int classifyKnn(Mat f);
        void trainKnn(Mat trainSamples, Mat trainClasses, int k);
        Mat features(Mat input, int size);

    private:
        bool trained;
        vector<CharSegment> segment(Plate input);
        Mat Preprocess(Mat in, int newSize);
        Mat getVisualHistogram(Mat *hist, int type);
        void drawVisualFeatures(Mat character, Mat hhist, Mat vhist, Mat lowData);
        Mat ProjectedHistogram(Mat img, int t);
        bool verifySizes(Mat r);
        cv::Ptr<cv::ml::ANN_MLP> ann = cv::ml::ANN_MLP::create();
//        cv::ml::KNearest knnClassifier;
        cv::Ptr<ml::KNearest>  knn = ml::KNearest::create();
    
        int K;
};

#endif /* orc_hpp */
