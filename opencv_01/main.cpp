#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* Listing 2.5  macro
 */
#if 1

#define Mpixel(image,x,y) ((uchar*)(image.data + y*(image.step)))[x]
//#define Mpixel(image,x,y)((uchar*)(image.data + y*(image.step[0]))) [x]
// step[0] 是矩阵中一行元素的字节数
//step[1]是矩阵中一个元素字节数

//#define Mpixel(image,x,y) ( (uchar *) ( ((image).data) + (y)*((image).step) ) ) [(x)]
int main(int argc, char* argv[]){
     Mat image, image2;
     if (argc != 2) { cout << "needs 1 argument, e.g. image.jpg" << endl ; exit (0) ;}
     image = imread(argv[1],0);
     image2.create(image.size(),CV_8UC1); // create 不能设置初始值
    for (int x = 0; x < image.cols; x++) {
        for (int y = 0; y < image.rows; y++) {
            if(x == y){
                Mpixel(image2,x,y)=255;
            }else{
                Mpixel(image2,x,y) = Mpixel(image,x,y);
            }
        }
    }
    namedWindow("regional image",WINDOW_AUTOSIZE);// lect err
    imshow("regional image",image);
    namedWindow("destination image",WINDOW_AUTOSIZE);// lect err
    imshow("destination image",image2);
    waitKey(0);

    return 0;
}


#endif

/*  lect demo3   at() channel 3      
 * 取像素点的灰度值或者RGB值
 * Mat_<uchar> img = image;
 * */
#if 0

int main(int argc, char* argv[]){
    Mat image, image2;
    if (argc != 2) { cout << "needs 1 argument, e.g. image.jpg" << endl ; exit (0) ;}
    image = imread(argv[1],1);// flags 0 to transform to greyscale
//    image = imread(argv[1],1);// 此处如果是1 则depth 变大，复制时step 变化。
    image2 = imread(argv[1],0);
    image2.create(image.size(),CV_8UC3);
    for (int x = 0; x < image.cols; x++) {
        for (int y = 0; y < image.rows; y++) {
            Vec3b pixel_image = image.at<Vec3b>(y,x);
            Vec3b pixel_image2 = image.at<Vec3b>(y,x);
            if(x == y){
//                image2.at<uchar>(y,x) =255;
                pixel_image2[0] = 0;
                pixel_image2[1] = 255;
                pixel_image2[2] = 0;
            } else{
//                image2.at<uchar>(y,x) = image.at<uchar>(y,x);
                pixel_image2[0] = pixel_image[0];
                pixel_image2[1] = pixel_image[1];
                pixel_image2[2] = pixel_image[2];
            }
            image2.at<Vec3b>(y,x) =pixel_image2;
        }
    }
    namedWindow("regional image",WINDOW_AUTOSIZE);// lect err
    imshow("regional image",image);
    namedWindow("destination image",WINDOW_AUTOSIZE);// lect err
    imshow("destination image",image2);
    waitKey(0);
    return 0;
}
#endif

// lect demo3   at()
#if 0
int main(int argc, char* argv[]){
    Mat image, image2;
    if (argc != 2) { cout << "needs 1 argument, e.g. image.jpg" << endl ; exit (0) ;}
    image = imread(argv[1],0);// flags 0 to transform to greyscale
//    image = imread(argv[1],1);// 此处如果是1 则depth 变大，复制时step 变化。
    image2 = imread(argv[1],0);
    image2.create(image.size(),CV_8UC1);
    for (int x = 0; x < image.cols; x++) {
        for (int y = 0; y < image.rows; y++) {
            if(x == y){
                image2.at<uchar>(y,x) =255;
            } else{
                image2.at<uchar>(y,x) = image.at<uchar>(y,x);
            }
        }
    }
    namedWindow("regional image",WINDOW_AUTOSIZE);// lect err
    imshow("regional image",image);
    namedWindow("destination image",WINDOW_AUTOSIZE);// lect err
    imshow("destination image",image2);
    waitKey(0);
    return 0;
}
#endif


//lect demo2
#if 0

int main(int argc , char** argv) {
//if there is no argument, exit
    if (argc != 2) { cout << "needs 1 argument, e.g. image.jpg" << endl ; exit (0) ;}
// create windows to show images
    namedWindow("Color" ,0) ;
    namedWindow("Grey" ,0) ; //create Mat instances
    Mat imagecolor , imagegrey ;
//load the file name in the argument onto ’image’
    imagecolor=imread ( argv [ 1 ] ) ;
//convert to greyscale
    cvtColor ( imagecolor , imagegrey , COLOR_BGR2GRAY) ; //lect error
//show the windows
    imshow("Color" , imagecolor ) ;
    imshow("Grey" , imagegrey) ;
//hold the image until the user presses any key waitKey(0) ;
//write the image into a file
    imwrite("grey.jpg", imagegrey);
    cout << "color image channels " << imagecolor.channels() <<endl; cout << "grey image channels " << imagegrey . channels () << endl ;
    waitKey(0);

    return 0 ;

}
#endif

//lect demo1
#if 0
int main(int argc, char * argv[]){
    if (argc != 2) { cout << "needs 1 argument, e.g. image.jpg" << endl ; exit (0) ;}
    namedWindow("win01",0);
    Mat image1 = imread(argv[1]);
    imshow("win_01",image1);
    waitKey(0);

    return 0;
}

#endif

#if 0
//ppt p1    convert to gray
int main(int argc , char** argv){
    Mat imageColor, imageGrey;
    imageColor = imread(argv[1],1);
    imageGrey = imread(argv[1],0);
    imwrite("grey01.jpg",imageGrey);
    return 0;
}
#endif
#if 0

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

//===========================//
//testing
#if 0
void createAlphaMat(Mat &mat)
{
    for(int i = 0 ; i < mat.rows ; i ++) {
        for(int j = 0 ; j < mat.cols ; j ++) {
            Vec4b &rgba = mat.at<Vec4b>(i,j);
            rgba[0] = UCHAR_MAX ;
            rgba[1] = saturate_cast<uchar>((float (mat.cols - j)) / ((float)mat.cols) * UCHAR_MAX);
            rgba[2] = saturate_cast<uchar>((float (mat.rows - i)) / ((float)mat.rows) * UCHAR_MAX);
            rgba[3] = saturate_cast<uchar>(0.5 * (rgba[1] + rgba[2]));
        }
    }
}
int main()
{
    Mat mat(480,640,CV_8UC4);
    createAlphaMat(mat);

    vector<int> compression_params ;
    compression_params.push_back(IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);

    imwrite("alpha.png",mat,compression_params);
    return 0;
}
#endif
