#include "ImageDestrip.h"

ImageDestrip::ImageDestrip(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    cutRows = 5;
    cutCols = 5;
    workThread = new WorkThread;
    thread = new QThread(this);
    workThread->moveToThread(thread);

    thread->start();

    ui.comboBox_mode->addItems({ "Single band", "Multi band" });
    // data swap
    connect(this, &ImageDestrip::sendImagePath, workThread, &WorkThread::receiveImagePath);
    connect(this, &ImageDestrip::sendResultSavePath, workThread, &WorkThread::receiveResultSavePath);
    connect(workThread, &WorkThread::sendImageSize, this, &ImageDestrip::receiveImageSize);
    connect(workThread, &WorkThread::sendImagePatches, this, &ImageDestrip::receiveImagePatches);
    connect(workThread, &WorkThread::sendDestripSignal, this, &ImageDestrip::receiveDestripSignal);
    connect(workThread, &WorkThread::sendDestripDetail, this, &ImageDestrip::receiveDestripDetail);
    connect(workThread, &WorkThread::sendWritingSignal, this, &ImageDestrip::receiveWritingSignal);
    connect(workThread, &WorkThread::sendFinishSignal, this, &ImageDestrip::receiveFinishSignal);
    connect(workThread, &WorkThread::sendFFTMsg, this, &ImageDestrip::receiveFFTMsg);

    connect(workThread, &WorkThread::sendMulSplitMsg, this, &ImageDestrip::receiveMulSplitMsg);
    connect(workThread, &WorkThread::sendMulBandMsg, this, &ImageDestrip::receiveMulBandMsg);
    // exec
    connect(this, &ImageDestrip::startWorkThread_oneband, workThread, &WorkThread::oneband_destrip);
    connect(this, &ImageDestrip::startWorkThread_mulband, workThread, &WorkThread::mulband_destrip);
    // destroy
    connect(this, &ImageDestrip::destroyed, this, &ImageDestrip::killSubThread);
}
// UI interface functions
void ImageDestrip::on_pushButton_OK_clicked() {
    ui.textEdit_log->clear();
    ui.textEdit_log->append("[Info] Working threads started.");
    if (qfileName != "" && qdstDir != "") {
        emit sendImagePath(qfileName);
        emit sendResultSavePath(qdstDir);
    }
    else {
        QMessageBox::information(this, "Error", "No input/output specified. ");
    }
    if (ui.comboBox_mode->currentIndex() == 0)  emit startWorkThread_oneband();
    if (ui.comboBox_mode->currentIndex() == 1)  emit startWorkThread_mulband();
}

void ImageDestrip::on_pushButton_src_clicked() {
    qfileName = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("tiff, tif (*.tiff *.tif"));
    ui.lineEditInput->setText(qfileName);
    ui.textEdit_log->append("Open image: " + qfileName);
}

void ImageDestrip::on_pushButton_dst_clicked() {
    qdstDir = QFileDialog::getExistingDirectory(this, "Select image path...", ".");
    ui.lineEditOutput->setText(qdstDir);
    ui.textEdit_log->append("Set destination folder: " + qdstDir);
}
// 
void ImageDestrip::receiveImageSize(int cutRows, int cutCols) {
    ui.textEdit_log->append("Image size from sub thread: " + QString::number(cutRows) + "*" + QString::number(cutCols));
}

void ImageDestrip::receiveImagePatches(int cutRows, int cutCols) {
    ui.textEdit_log->append("[Info] Image patches set to: " + QString::number(cutRows) + " * " + QString::number(cutCols));
}

void ImageDestrip::receiveDestripSignal() {
    ui.textEdit_log->append("[Info] Destrip begin...");
}

void ImageDestrip::receiveDestripDetail(int i, int j) {
    ui.textEdit_log->append("[Info] Destrip part: (" + QString::number(i) + ", " + QString::number(j) + ")");
}

void ImageDestrip::receiveWritingSignal() {
    ui.textEdit_log->append("[Info] Destrip finished...");
    ui.textEdit_log->append("[Info] Writing result begin. This may take a while...");
}

void ImageDestrip::receiveFinishSignal() {
    ui.textEdit_log->append("[Info] Writing result finished.");
}

void ImageDestrip::receiveFFTMsg(QString str) {
    ui.textEdit_log->append("-- Convert to " + str + " domain...");
}

void ImageDestrip::receiveMulSplitMsg() {
    ui.textEdit_log->append("Multispectral data split succeed. ");
}

void ImageDestrip::receiveMulBandMsg(int size) {
    ui.textEdit_log->append("[Info] Band Count: " + QString::number(size));
}

void ImageDestrip::killSubThread() {
    if (thread->isRunning() == false)  return;
    thread->quit();
    thread->wait();
    delete workThread;
}