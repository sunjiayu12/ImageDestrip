/********************************************************************************
** Form generated from reading UI file 'ImageDestrip.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEDESTRIP_H
#define UI_IMAGEDESTRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageDestripClass
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditInput;
    QLineEdit *lineEditOutput;
    QPushButton *pushButton_src;
    QPushButton *pushButton_dst;
    QLabel *label_3;
    QComboBox *comboBox_mode;
    QPushButton *pushButton_OK;
    QTextEdit *textEdit_log;

    void setupUi(QWidget *ImageDestripClass)
    {
        if (ImageDestripClass->objectName().isEmpty())
            ImageDestripClass->setObjectName(QStringLiteral("ImageDestripClass"));
        ImageDestripClass->resize(513, 328);
        label = new QLabel(ImageDestripClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 21, 21));
        label_2 = new QLabel(ImageDestripClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 40, 21, 21));
        lineEditInput = new QLineEdit(ImageDestripClass);
        lineEditInput->setObjectName(QStringLiteral("lineEditInput"));
        lineEditInput->setGeometry(QRect(60, 10, 191, 20));
        lineEditOutput = new QLineEdit(ImageDestripClass);
        lineEditOutput->setObjectName(QStringLiteral("lineEditOutput"));
        lineEditOutput->setGeometry(QRect(60, 40, 191, 20));
        pushButton_src = new QPushButton(ImageDestripClass);
        pushButton_src->setObjectName(QStringLiteral("pushButton_src"));
        pushButton_src->setGeometry(QRect(260, 10, 31, 23));
        pushButton_dst = new QPushButton(ImageDestripClass);
        pushButton_dst->setObjectName(QStringLiteral("pushButton_dst"));
        pushButton_dst->setGeometry(QRect(260, 40, 31, 23));
        label_3 = new QLabel(ImageDestripClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 10, 111, 21));
        comboBox_mode = new QComboBox(ImageDestripClass);
        comboBox_mode->setObjectName(QStringLiteral("comboBox_mode"));
        comboBox_mode->setGeometry(QRect(300, 40, 101, 22));
        pushButton_OK = new QPushButton(ImageDestripClass);
        pushButton_OK->setObjectName(QStringLiteral("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(410, 10, 75, 51));
        textEdit_log = new QTextEdit(ImageDestripClass);
        textEdit_log->setObjectName(QStringLiteral("textEdit_log"));
        textEdit_log->setGeometry(QRect(30, 70, 461, 251));

        retranslateUi(ImageDestripClass);

        QMetaObject::connectSlotsByName(ImageDestripClass);
    } // setupUi

    void retranslateUi(QWidget *ImageDestripClass)
    {
        ImageDestripClass->setWindowTitle(QApplication::translate("ImageDestripClass", "ImageDestrip", nullptr));
        label->setText(QApplication::translate("ImageDestripClass", "src", nullptr));
        label_2->setText(QApplication::translate("ImageDestripClass", "dst", nullptr));
        pushButton_src->setText(QApplication::translate("ImageDestripClass", "...", nullptr));
        pushButton_dst->setText(QApplication::translate("ImageDestripClass", "...", nullptr));
        label_3->setText(QApplication::translate("ImageDestripClass", "select image type:", nullptr));
        pushButton_OK->setText(QApplication::translate("ImageDestripClass", "Exec", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageDestripClass: public Ui_ImageDestripClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEDESTRIP_H
