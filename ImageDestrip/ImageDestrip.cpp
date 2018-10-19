#include "ImageDestrip.h"

ImageDestrip::ImageDestrip(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    qfileName = "";
    qdstDir = "";
    ui.comboBox_mode->addItems({ "Single band", "Multi band" });
    connect(ui.pushButton_OK, SIGNAL(clicked()), this, SLOT(pushButton_OK_clicked()));
    connect(ui.pushButton_src, SIGNAL(clicked()), this, SLOT(pushButton_src_clicked()));
    connect(ui.pushButton_dst, SIGNAL(clicked()), this, SLOT(pushButton_dst_clicked()));
}

void ImageDestrip::pushButton_OK_clicked() {
    if (fileName == "") {
        QMessageBox::information(this, "Error", "No input files specified. ");
        return;
    }
    if (dstDir == "") {
        QMessageBox::information(this, "Error", "No output folder specified. ");
        return;
    }
    if (ui.comboBox_mode->currentIndex() == 0)  oneband_destrip();
    if (ui.comboBox_mode->currentIndex() == 1)  mulband_destrip();
}

void ImageDestrip::pushButton_src_clicked() {
    qfileName = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("tiff, tif (*.tiff *.tif"));
    ui.lineEditInput->setText(qfileName);
    ui.textEdit_log->append("Open image: " + qfileName);
    QTextCodec* code = QTextCodec::codecForName("gb2312");
    fileName = code->fromUnicode(qfileName).data();
}

void ImageDestrip::pushButton_dst_clicked() {
    qdstDir = QFileDialog::getExistingDirectory(this, "Select image path...", ".");
    ui.lineEditOutput->setText(qdstDir);
    ui.textEdit_log->append("Set destination folder: " + qdstDir);
    QTextCodec* code = QTextCodec::codecForName("gb2312");
    dstDir = code->fromUnicode(qdstDir).data();
}

void ImageDestrip::oneband_destrip() {
    // load image
    cv::Mat srcImg = cv::imread(fileName, CV_LOAD_IMAGE_ANYDEPTH);
    // preprocessing
    for (int i = 0; i < srcImg.rows; i++) {
        srcImg.at<short>(i, 0) = srcImg.at<short>(i, 2);
        srcImg.at<short>(i, 1) = srcImg.at<short>(i, 3);
        srcImg.at<short>(i, srcImg.cols - 2) = srcImg.at<short>(i, srcImg.cols - 4);
        srcImg.at<short>(i, srcImg.cols - 1) = srcImg.at<short>(i, srcImg.cols - 3);
    }
    for (int i = 0; i < srcImg.cols; i++) {
        srcImg.at<short>(0, i) = srcImg.at<short>(2, i);
        srcImg.at<short>(1, i) = srcImg.at<short>(3, i);
        srcImg.at<short>(srcImg.rows - 2, i) = srcImg.at<short>(srcImg.rows - 4, i);
        srcImg.at<short>(srcImg.rows - 1, i) = srcImg.at<short>(srcImg.rows - 3, i);
    }

    // cut image
    ui.textEdit_log->append("Cutting image by " + QString::number(CutRows) + "*" + QString::number(CutCols));
    qApp->processEvents();
    vector<cv::Mat> vecPart;
    Division(srcImg, vecPart);
    srcImg.release();
    // fft, mask and ifft
    ui.textEdit_log->append("Destrip begin...");
    qApp->processEvents();
    for (int i = 0; i < CutRows * CutCols; i++) {
        vector<cv::Mat> planes = FFT(vecPart[i]);
        ui.textEdit_log->append("-- Delete destrip noise...");
        qApp->processEvents();
        Mask(planes);
        Ifft(vecPart[i], planes);
    }
    ui.textEdit_log->append("Destrip finished...");
    qApp->processEvents();
    // stitch
    cv::Mat dstImg(srcImg.rows, srcImg.cols, CV_16U, cv::Scalar(0));
    Mosaic(vecPart, dstImg);
    ui.textEdit_log->append("Writing result begin.");
    cv::imwrite(dstDir + "/dstImg.tif", dstImg);
    ui.textEdit_log->append("Writing result finished.");
    qApp->processEvents();
}

void ImageDestrip::Division(cv::Mat& srcImg, vector<cv::Mat>& ceilImg) {
    if (srcImg.empty()) {
        QMessageBox::information(this, "Error", "Image size is 0 * 0. ");
        return;
    }
    ui.textEdit_log->append("Size: " + QString::number(srcImg.rows) + ", " + QString::number(srcImg.cols));

    int ceil_height = srcImg.rows / CutRows;
    int ceil_width = srcImg.cols / CutCols;

    ui.textEdit_log->append("Cut image begin...");
    qApp->processEvents();

    for (int i = 0; i < CutRows; i++) {
        for (int j = 0; j < CutCols; j++) {
            cv::Rect rect(j * ceil_width, i * ceil_height, ceil_width, ceil_height);
            ceilImg.push_back(srcImg(rect));
        }
    }
    ui.textEdit_log->append("Cut image finished. ");
    ui.textEdit_log->append("Number of blocks: " + QString::number(ceilImg.size()));
    ui.textEdit_log->append("Destrip done. ");
    qApp->processEvents();
}

vector<cv::Mat> ImageDestrip::FFT(const cv::Mat& src) {
    int m = cv::getOptimalDFTSize(src.rows);
    int n = cv::getOptimalDFTSize(src.cols);
    
    cv::Mat padded;
    cv::copyMakeBorder(src, padded, 0, m - src.rows, 0, n - src.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));

    vector<cv::Mat> planes{ cv::Mat_<float>(padded), cv::Mat::zeros(padded.size(), CV_32F) };
    cv::Mat complexSrc;
    cv::merge(&planes[0], 2, complexSrc);

    ui.textEdit_log->append("-- Convert to complex domain...");
    qApp->processEvents();
    cv::dft(complexSrc, complexSrc);

    // -> log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
    cv::split(complexSrc, planes);
    return planes;
}

void ImageDestrip::Ifft(cv::Mat& src, vector<cv::Mat>& planes) {
    cv::Mat complexI, invFFT;
    cv::merge(&planes[0], 2, complexI);
    ui.textEdit_log->append("-- Convert to real domain...");
    qApp->processEvents();
    cv::idft(complexI, invFFT, cv::DFT_SCALE | cv::DFT_REAL_OUTPUT);
    invFFT.convertTo(invFFT, CV_16UC1);
    src = invFFT(cv::Rect(0, 0, src.cols, src.rows));
}

void ImageDestrip::Mask(vector<cv::Mat>& fftMat) {
    cv::Mat mask(fftMat[0].size(), CV_32F, cv::Scalar::all(1));
    for (int i = mask.rows / 4; i < 3 * mask.rows / 4; i++) {
        for (int j = 0; j < mask.cols / 50; j++) {
            mask.at<float>(i, j) = 0;
        }
        for (int j = mask.cols - mask.cols / 50; j < mask.cols; j++) {
            mask.at<float>(i, j) = 0;
        }
    }
    for (int j = mask.cols / 4; j < 3 * mask.cols / 4; j++) {
        for (int i = 0; i < mask.rows / 50; i++) {
            mask.at<float>(i, j) = 0;
        }
        for (int i = mask.rows - mask.rows / 50; i < mask.rows; i++) {
            mask.at<float>(i, j) = 0;
        }
    }
    for (auto& img : fftMat) {
        img = img.mul(mask);
    }
}

void ImageDestrip::Mosaic(vector<cv::Mat>& ceilImg, cv::Mat& dst) {
    if (ceilImg.empty()) {
        QMessageBox::information(this, "Error", "Mat vector is empty!");
        return;
    }
    int singleHeight = ceilImg[0].rows;
    int singleWidth = ceilImg[0].cols;
    int totalHeight = CutRows * singleHeight;
    int totalWidth = CutCols * singleWidth;

    if (totalHeight != dst.rows || totalWidth != dst.cols) {
        QMessageBox::information(this, "Error", "Image sequence and destination image size not matched!");
        return;
    }
    ui.textEdit_log->append("Mosaic begin...");
    int vecIdx = 0;
    for (int i = 0; i < CutRows; i++) {
        for (int j = 0; j < CutCols; j++) {
            ui.textEdit_log->append("Copying x: " + QString::number(i) + ", y: " + QString::number(j) + " begin...");
            cv::Mat imageROI = dst(cv::Rect(j * singleWidth, i * singleHeight, singleWidth, singleHeight));
            ceilImg[vecIdx].copyTo(imageROI);
            vecIdx++;
            ui.textEdit_log->append("Copying x: " + QString::number(i) + ", y: " + QString::number(j) + " finished...");
        }
    }
}

vector<cv::Mat> ImageDestrip::gdal2Mat() {
    GDALAllRegister();
    GDALDataset* poDataset = (GDALDataset*)GDALOpen(fileName.c_str(), GA_ReadOnly);
    int bandNum = poDataset->GetRasterCount();
    vector<cv::Mat> vecImg;
    for (int i = 0; i < bandNum; i++) {
        GDALRasterBand* poBand = poDataset->GetRasterBand(i + 1);
        int rows = poBand->GetYSize();
        int cols = poBand->GetXSize();
        ushort* pBuf = new ushort[rows * cols];
        poBand->RasterIO(GF_Read, 0, 0, cols, rows, pBuf, cols, rows, GDT_UInt16, 0, 0);
        vecImg.push_back(cv::Mat(rows, cols, CV_16U, pBuf));
    }
    ui.textEdit_log->append("Multispectral data split succeed. ");
    qApp->processEvents();
    GDALClose(poDataset);
    GDALDestroyDriverManager();
    return vecImg;
}

void ImageDestrip::mat2gdal(const vector<cv::Mat>& vecImg) {
    int rows = vecImg[0].rows;
    int cols = vecImg[0].cols;

    GDALAllRegister();
    GDALDriver* poDriver = GetGDALDriverManager()->GetDriverByName("ENVI");
    string tmp = dstDir + "/" + "restored.tif";
    GDALDataset* poDataset = poDriver->Create(tmp.c_str(), cols, rows, vecImg.size(), GDT_UInt16, NULL);

    GDALRasterBand* poBand = NULL;
    ushort* ppafScan = new ushort[rows * cols];
    cv::Mat tmpImg;

    int nr = rows;
    int nc = cols;
    for (int i = 1; i <= vecImg.size(); i++) {
        poBand = poDataset->GetRasterBand(i);
        tmpImg = vecImg[i - 1];
        if (tmpImg.isContinuous()) {
            nc *= nr;
            nr = 1;
        }
        for (int r = 0; r < nr; r++) {
            int tmpI = r * cols;
            ushort* p = tmpImg.ptr<ushort>(r);
            for (int c = 0; c < nc; c++)  ppafScan[tmpI + c] = p[c];
        }
        poBand->RasterIO(GF_Write, 0, 0, cols, rows, ppafScan, cols, rows, GDT_UInt16, 0, 0);
    }
    delete[] ppafScan; ppafScan = NULL;
    GDALClose(poDataset);
    GDALDestroyDriverManager();
}

void ImageDestrip::mulband_destrip() {
    vector<cv::Mat> vecImg = gdal2Mat();
    ui.textEdit_log->append("imgMat size: " + QString::number(vecImg.size()));
    for (int i = 0; i < vecImg.size(); i++) {
        cv::imwrite(dstDir + "/" + to_string(i + 1) + ".tif", vecImg[i]);
        vector<cv::Mat> planes = FFT(vecImg[i]);
        ui.textEdit_log->append("-- Delete destrip noise...");
        qApp->processEvents();
        Mask(planes);
        Ifft(vecImg[i], planes);
        cv::imwrite(dstDir + "/" + to_string(i + 1) + "_cleared.tif", vecImg[i]);
    }
    ui.textEdit_log->append("Write finished. ");
    mat2gdal(vecImg);
    qApp->processEvents();
}