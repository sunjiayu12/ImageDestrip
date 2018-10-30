#pragma once

// for std
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
// for qt
#include <QtWidgets/QWidget>
#include <QMessageBox>
#include <QFile>
#include <qFileDialog>
#include <QDebug>
#include <QTextCodec>
#include <QThread>
#include "WorkThread.h"
#include "ui_ImageDestrip.h"
// for opencv
#include "opencv2/opencv.hpp"
// for gdal
#include "gdal_priv.h"

using namespace std;

class ImageDestrip : public QWidget
{
    Q_OBJECT

public:
    ImageDestrip(QWidget *parent = Q_NULLPTR);

//public:
//    // main process
//    void oneband_destrip();
//    void mulband_destrip();
//
//public:
//    // related destrip methods
//    vector<cv::Mat> FFT(const cv::Mat& src);
//    void Ifft(cv::Mat& src, vector<cv::Mat>& planes);
//    void Mask(vector<cv::Mat>& fftMat);
//
//public:
//    // Multispectrum
//    vector<cv::Mat> gdal2Mat();
//    void mat2gdal(const vector<cv::Mat>& vecImg);

public:
    void receiveImageSize(int, int);
    void receiveImagePatches(int, int);
    void receiveDestripSignal();
    void receiveDestripDetail(int, int);
    void receiveWritingSignal();
    void receiveFinishSignal();
    void receiveFFTMsg(QString);
    // multispectral
    void receiveMulSplitMsg();
    void receiveMulBandMsg(int);

private slots:
    void on_pushButton_OK_clicked();
    void on_pushButton_src_clicked();
    void on_pushButton_dst_clicked();

signals:
    void startWorkThread_oneband();
    void startWorkThread_mulband();
    void sendImagePath(QString);
    void sendResultSavePath(QString);

private:
    Ui::ImageDestripClass ui;
    QString qfileName, qdstDir;
    string fileName, dstDir;
    size_t cutRows, cutCols;

    WorkThread* workThread;
    QThread* thread;
};
