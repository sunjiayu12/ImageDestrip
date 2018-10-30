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
#include "ui_ImageDestrip.h"
// for opencv
#include "opencv2/opencv.hpp"
// for gdal
#include "gdal_priv.h"

using namespace std;

class WorkThread : public QObject {
    Q_OBJECT
public:
    explicit WorkThread(QObject* parent = Q_NULLPTR);
public:
    // main process
    void oneband_destrip();
    void mulband_destrip();

public:
    // related destrip methods
    vector<cv::Mat> FFT(const cv::Mat& src);
    void Ifft(cv::Mat& src, vector<cv::Mat>& planes);
    void Mask(vector<cv::Mat>& fftMat);
    void PreProcess(cv::Mat& img);

public:
    // Multispectrum
    vector<cv::Mat> gdal2Mat();
    void mat2gdal(const vector<cv::Mat>& vecImg);

public:
    void receiveImagePath(QString);
    void receiveResultSavePath(QString);

signals:
    void sendImageSize(int, int);
    void sendImagePatches(int, int);
    void sendDestripSignal();
    void sendDestripDetail(int, int);
    void sendWritingSignal();
    void sendFinishSignal();
    // multispectral
    void sendMulSplitMsg();
    void sendMulBandMsg(int);
    void sendFFTMsg(QString);

public slots:

protected:
    QString qfileName, qdstDir;
    string fileName, dstDir;
    int cutRows, cutCols;
};