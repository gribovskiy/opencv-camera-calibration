#include <opencv2/opencv.hpp>
//#include <cv.h>
//#include <highgui.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

int main()
{
    cv::FileStorage fs("../opencv-fisheye-calibration/results.xml", cv::FileStorage::READ);
    Mat tmp;
    fs["camera_matrix"] >> tmp;
    cv::Matx33d intrinsic(tmp);

    Vec4d distCoeffs;
    fs["distortion_coefficients"] >> distCoeffs;
    fs.release();

    cout << intrinsic << endl;
    cout << distCoeffs << endl;

    VideoCapture capture = VideoCapture(0);
    Mat image;

    // show the undistorted results
    Mat imageUndistorted;
    while(1)
    {
        capture >> image;

        Matx33d newK = intrinsic;
//        Matx33d newK = Matx33d::eye(); // doesn't work

        fisheye::undistortImage(image, imageUndistorted, intrinsic, distCoeffs, newK);

        imshow("win1", image);
        imshow("win2", imageUndistorted);

        int key = waitKey(1);

        if(key==27)
            return 0;
    }

    capture.release();

    return 0;
}
