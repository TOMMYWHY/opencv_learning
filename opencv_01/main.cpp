#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


#if 1

int main(){
    Mat m = imread("test01.jpeg");
    Mat_<Vec3d> m2 =m;
    for (int y = 21; y < 42; y++) {
        for (int x = 2; x < 21; x++) {
            if(pow(double(x-11),2) + pow(double(y-31),2)-64.0<0.00001){
                m2(x,y)=Vec3b(0,0,255);
            }
        }
    }

    if (!m.data) {
        std::cout << "Image not loaded";
        return -1;
    }
    imshow("demo4", m2);
    waitKey(0);
    return 0;

}
#endif


#if 0

int main(){
    Mat m = imread("test01.jpeg");
    Vec3i color;

    for (int col = 20; col < 140; col++) {
        for (int row = 2; row < 120; row++) {
            color[0] = (int)(*(m.data + m.step[0]*row + m.step[1]*col)); //B
            color[1] = (int)(*(m.data + m.step[0]*row + m.step[1]*col+m.elemSize1()));//G
            color[2] = (int)(*(m.data + m.step[0]*row + m.step[1]*col+m.elemSize1()*2));//R
            cout << color[0] <<","<<color[1] << ","<<color[2]<<"==> ";

            color[0] = 255;
            color[1] = 0;
            color[2] = 0;
            *(m.data+m.step[0]*row + m.step[1]*col) =color[0];
            *(m.data+m.step[0]*row + m.step[1]*col+m.elemSize1()) =color[1];
            *(m.data+m.step[0]*row + m.step[1]*col+m.elemSize1()*2) =color[2];
            cout <<(int)*(m.data+m.step[0]*row + m.step[1]*col)<<","
            <<(int)*(m.data+m.step[0]*row + m.step[1]*col+1)<<","
            <<(int)*(m.data+m.step[0]*row + m.step[1]*col+2)
            <<endl;
        }
    }

    if (!m.data) {
        std::cout << "Image not loaded";
        return -1;
    }
    imshow("demo3", m);
    waitKey(0);
    return 0;

}
#endif

#if 0

int main(){
    Mat srcImage = imread("test01.jpeg",IMREAD_GRAYSCALE);
    if (!srcImage.data) {
        std::cout << "Image not loaded";
        return -1;
    }
    imshow("demo2", srcImage);
    waitKey(0);
    return 0;

}
#endif

#if 0
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
