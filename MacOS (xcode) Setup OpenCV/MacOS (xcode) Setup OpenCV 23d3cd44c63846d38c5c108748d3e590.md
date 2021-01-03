# MacOS (xcode) Setup OpenCV

## 1. intall homebrew

Homebrew can help you easily download OpenCV and other dependencies. 

## 2. install opencv and pkg-config

In your terminal enter the following commends:

> brew intall opencv
brew install pkg-config

## 3. Set up xcode

### 3.1 Head Search Path

In Building settings,  add /usr/local/Cellar/opencv/4.5.0_5/include into **head search path** 

> Please check your opencv file path, because sometimes it locates in /usr/local/Cellar/opencv/4.5.0_5/include/opencv4

You could use finder go to check the opencv path.

### 3.2 Library Search Path

In Building settings,  add /usr/local/Cellar/opencv/4.5.0_5/lib into **Library Search Path**

### 3.3 Other Linker Flags

In your terminal enter the following commends:

> pkg-config --cflags --libs opencv4

Then add lopencv_gapi -lopencv_stitching -lopencv_alphamat -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dnn_superres -lopencv_dpm -lopencv_highgui -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_intensity_transform -lopencv_line_descriptor -lopencv_mcc -lopencv_quality -lopencv_rapid -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_sfm -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_optflow -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_dnn -lopencv_plot -lopencv_videostab -lopencv_videoio -lopencv_viz -lopencv_xfeatures2d -lopencv_shape -lopencv_ml -lopencv_ximgproc -lopencv_video -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core to your **Other links**

## To run in commend line
MacOSX (Xcode):
    export OpenCV_DIR="~/OpenCV/build"
    mkdir build
    cd build
    cmake -G Xcode -D OpenCV_DIR=$OpenCV_DIR ..
    open ANPR.xcodeproj
    
## Old OpenCV package

**Note that most of the time you can just use the "include all" header: #include <opencv2/opencv.hpp>**

- opencv/cv.h: #include <opencv2/opencv.hpp>
- highgui.h: #include <opencv2/highgui.hpp>
- cvaux.h: #include <opencv/cvaux.h>
- CV_BGR2GRAY: cv::COLOR_BGR2GRAY
- CV_THRESH_OTSU: cv::THRESH_OTSU
- CV_THRESH_BINARY: cv::THRESH_BINARY
- cv::MOP_CLOSE: cv::MORPH_CLOSE
