#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#if 1
int main(){
    Mat m = Mat(400,400,CV_8U,Scalar(0));
    for (int col = 0; col < 400; col++) {
        for (int row = 195; row < 205; row++) {
            cout << (int)(*(m.data + m.step[0]*row+m.step[1]*col)) << "==> ";
            *(m.data + m.step[0]*row + m.step[1]*col) =255;
            cout << (int)(*(m.data + m.step[0]*row+m.step[1]*col)) << endl;
        }
    }
    imshow("testing",m);
    waitKey(0);
    return 0;
}
#endif

#if 0
int main(){
    Mat m = Mat(800,600,CV_8UC3,Scalar(0,0,255));
    cout<< m <<endl;
    imshow("testing",m);
    waitKey(0);
    return 0;
}
#endif

#if 0
int main() {
    cout << "testing..!!!!"<<endl;
    Mat srcImage = imread("test01.jpeg");
    if (!srcImage.data) {
        std::cout << "Image not loaded";
        return -1;
    }
    imshow("demo1", srcImage);
//    cout<< srcImage <<endl;
    waitKey(0);
    return 0;
}

#endif
