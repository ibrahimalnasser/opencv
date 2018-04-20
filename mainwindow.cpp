#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<QTime>

using namespace std;
using namespace cv;

void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    const int fps=20;
    Mat frame;
    Mat Pre_frame;
    VideoCapture vid(0);
if(!vid.isOpened()){

}
while(vid.read(frame))
{
if(Pre_frame==frame){
    imshow("Webcmae",frame);
    delay(1000/fps);
    Pre_frame=frame;
    //here the last work--------------------------------------------------------------------
}else {
    Pre_frame=frame;
  QDebug()<<"There is no difference";
}
}

//    // read an image
//    cv::Mat image = cv::imread("C://Users//Ibrahim//Desktop//lambrecht.jpg", 1);
//    // create image window named "My Image"
//    cv::namedWindow("My Image");
//    // show the image on window
//    cv::imshow("My Image", image);
}

MainWindow::~MainWindow()
{
    delete ui;
}
