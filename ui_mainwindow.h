/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_10;
    QPushButton *finishButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpinBox *krenGradSpinBox;
    QSpinBox *krenMinSpinBox;
    QCheckBox *krenCheckBox;
    QPushButton *saveInfoButt;
    QPushButton *loadInfoButt;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpinBox *dolgGradSpinBox;
    QSpinBox *dolgMinSpinBox;
    QCheckBox *dolgotaCheckBox;
    QPushButton *openErrorListBtn;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QSpinBox *diffGradSpinBox;
    QSpinBox *diffMinSpinBox;
    QCheckBox *differentCheckBox;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpinBox *hoursBox;
    QLabel *label_8;
    QSpinBox *minutesBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *kursGradSpinBox;
    QSpinBox *kursMinSpinBox;
    QCheckBox *kursCheckBox;
    QPushButton *errorButton;
    QPushButton *continueButton;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSpinBox *shirGradSpinBox;
    QSpinBox *shirMinSpinBox;
    QCheckBox *shirotaCheckBox;
    QPushButton *startBut;
    QProgressBar *progressBar;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *displayTextEdit;
    QPushButton *backButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(278, 460);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        finishButton = new QPushButton(page);
        finishButton->setObjectName(QString::fromUtf8("finishButton"));
        finishButton->setAutoExclusive(false);

        gridLayout_10->addWidget(finishButton, 11, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        krenGradSpinBox = new QSpinBox(page);
        krenGradSpinBox->setObjectName(QString::fromUtf8("krenGradSpinBox"));
        krenGradSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        krenGradSpinBox->setReadOnly(true);
        krenGradSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        krenGradSpinBox->setMinimum(-90);
        krenGradSpinBox->setMaximum(90);
        krenGradSpinBox->setValue(-90);

        horizontalLayout_2->addWidget(krenGradSpinBox);

        krenMinSpinBox = new QSpinBox(page);
        krenMinSpinBox->setObjectName(QString::fromUtf8("krenMinSpinBox"));
        krenMinSpinBox->setReadOnly(true);
        krenMinSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        krenMinSpinBox->setMaximum(59);

        horizontalLayout_2->addWidget(krenMinSpinBox);

        krenCheckBox = new QCheckBox(page);
        krenCheckBox->setObjectName(QString::fromUtf8("krenCheckBox"));

        horizontalLayout_2->addWidget(krenCheckBox);


        gridLayout_10->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        saveInfoButt = new QPushButton(page);
        saveInfoButt->setObjectName(QString::fromUtf8("saveInfoButt"));

        gridLayout_10->addWidget(saveInfoButt, 5, 0, 1, 1);

        loadInfoButt = new QPushButton(page);
        loadInfoButt->setObjectName(QString::fromUtf8("loadInfoButt"));

        gridLayout_10->addWidget(loadInfoButt, 6, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        dolgGradSpinBox = new QSpinBox(page);
        dolgGradSpinBox->setObjectName(QString::fromUtf8("dolgGradSpinBox"));
        dolgGradSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dolgGradSpinBox->setReadOnly(true);
        dolgGradSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dolgGradSpinBox->setMinimum(-180);
        dolgGradSpinBox->setMaximum(180);
        dolgGradSpinBox->setValue(-180);

        horizontalLayout_4->addWidget(dolgGradSpinBox);

        dolgMinSpinBox = new QSpinBox(page);
        dolgMinSpinBox->setObjectName(QString::fromUtf8("dolgMinSpinBox"));
        dolgMinSpinBox->setReadOnly(true);
        dolgMinSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dolgMinSpinBox->setMaximum(59);

        horizontalLayout_4->addWidget(dolgMinSpinBox);

        dolgotaCheckBox = new QCheckBox(page);
        dolgotaCheckBox->setObjectName(QString::fromUtf8("dolgotaCheckBox"));
        dolgotaCheckBox->setChecked(false);

        horizontalLayout_4->addWidget(dolgotaCheckBox);


        gridLayout_10->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        openErrorListBtn = new QPushButton(page);
        openErrorListBtn->setObjectName(QString::fromUtf8("openErrorListBtn"));
        openErrorListBtn->setCheckable(false);
        openErrorListBtn->setAutoExclusive(false);

        gridLayout_10->addWidget(openErrorListBtn, 12, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        diffGradSpinBox = new QSpinBox(page);
        diffGradSpinBox->setObjectName(QString::fromUtf8("diffGradSpinBox"));
        diffGradSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        diffGradSpinBox->setReadOnly(true);
        diffGradSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        diffGradSpinBox->setMinimum(-90);
        diffGradSpinBox->setMaximum(90);
        diffGradSpinBox->setValue(-90);

        horizontalLayout->addWidget(diffGradSpinBox);

        diffMinSpinBox = new QSpinBox(page);
        diffMinSpinBox->setObjectName(QString::fromUtf8("diffMinSpinBox"));
        diffMinSpinBox->setReadOnly(true);
        diffMinSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        diffMinSpinBox->setMaximum(59);

        horizontalLayout->addWidget(diffMinSpinBox);

        differentCheckBox = new QCheckBox(page);
        differentCheckBox->setObjectName(QString::fromUtf8("differentCheckBox"));

        horizontalLayout->addWidget(differentCheckBox);


        gridLayout_10->addLayout(horizontalLayout, 4, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        hoursBox = new QSpinBox(page);
        hoursBox->setObjectName(QString::fromUtf8("hoursBox"));
        hoursBox->setAlignment(Qt::AlignCenter);
        hoursBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        hoursBox->setMaximum(100);

        horizontalLayout_7->addWidget(hoursBox);

        label_8 = new QLabel(page);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        minutesBox = new QSpinBox(page);
        minutesBox->setObjectName(QString::fromUtf8("minutesBox"));
        minutesBox->setAlignment(Qt::AlignCenter);
        minutesBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        minutesBox->setMaximum(59);

        horizontalLayout_7->addWidget(minutesBox);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        horizontalLayout_6->addLayout(horizontalLayout_8);


        gridLayout_10->addLayout(horizontalLayout_6, 8, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        kursGradSpinBox = new QSpinBox(page);
        kursGradSpinBox->setObjectName(QString::fromUtf8("kursGradSpinBox"));
        kursGradSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        kursGradSpinBox->setReadOnly(true);
        kursGradSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        kursGradSpinBox->setMinimum(0);
        kursGradSpinBox->setMaximum(360);
        kursGradSpinBox->setValue(0);

        horizontalLayout_3->addWidget(kursGradSpinBox);

        kursMinSpinBox = new QSpinBox(page);
        kursMinSpinBox->setObjectName(QString::fromUtf8("kursMinSpinBox"));
        kursMinSpinBox->setReadOnly(true);
        kursMinSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        kursMinSpinBox->setMaximum(59);

        horizontalLayout_3->addWidget(kursMinSpinBox);

        kursCheckBox = new QCheckBox(page);
        kursCheckBox->setObjectName(QString::fromUtf8("kursCheckBox"));

        horizontalLayout_3->addWidget(kursCheckBox);


        gridLayout_10->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        errorButton = new QPushButton(page);
        errorButton->setObjectName(QString::fromUtf8("errorButton"));

        gridLayout_10->addWidget(errorButton, 7, 0, 1, 1);

        continueButton = new QPushButton(page);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        continueButton->setAutoExclusive(false);

        gridLayout_10->addWidget(continueButton, 10, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        shirGradSpinBox = new QSpinBox(page);
        shirGradSpinBox->setObjectName(QString::fromUtf8("shirGradSpinBox"));
        shirGradSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        shirGradSpinBox->setReadOnly(true);
        shirGradSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        shirGradSpinBox->setMinimum(-90);
        shirGradSpinBox->setMaximum(90);
        shirGradSpinBox->setValue(-90);

        horizontalLayout_5->addWidget(shirGradSpinBox);

        shirMinSpinBox = new QSpinBox(page);
        shirMinSpinBox->setObjectName(QString::fromUtf8("shirMinSpinBox"));
        shirMinSpinBox->setReadOnly(true);
        shirMinSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        shirMinSpinBox->setMaximum(59);

        horizontalLayout_5->addWidget(shirMinSpinBox);

        shirotaCheckBox = new QCheckBox(page);
        shirotaCheckBox->setObjectName(QString::fromUtf8("shirotaCheckBox"));
        shirotaCheckBox->setChecked(true);

        horizontalLayout_5->addWidget(shirotaCheckBox);


        gridLayout_10->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        startBut = new QPushButton(page);
        startBut->setObjectName(QString::fromUtf8("startBut"));
        startBut->setAutoExclusive(false);

        gridLayout_10->addWidget(startBut, 9, 0, 1, 1);

        progressBar = new QProgressBar(page);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimum(0);
        progressBar->setValue(0);

        gridLayout_10->addWidget(progressBar, 13, 0, 1, 1);


        gridLayout->addLayout(gridLayout_10, 0, 1, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        displayTextEdit = new QTextEdit(page_2);
        displayTextEdit->setObjectName(QString::fromUtf8("displayTextEdit"));
        displayTextEdit->setReadOnly(true);

        verticalLayout_3->addWidget(displayTextEdit);

        backButton = new QPushButton(page_2);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setAutoExclusive(false);

        verticalLayout_3->addWidget(backButton);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 278, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        finishButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\232\321\200\320\265\320\275", nullptr));
        krenGradSpinBox->setSuffix(QApplication::translate("MainWindow", "\302\260", nullptr));
        krenMinSpinBox->setSuffix(QApplication::translate("MainWindow", "'", nullptr));
        krenCheckBox->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        saveInfoButt->setText(QApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\270 \321\201\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\202\320\265\320\272\321\203\321\211\320\270\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", nullptr));
        loadInfoButt->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\277\320\276\321\201\320\273\320\265\320\264\320\275\320\270\320\265 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\273\320\263\320\276\321\202\320\260", nullptr));
        dolgGradSpinBox->setSuffix(QApplication::translate("MainWindow", "\302\260", nullptr));
        dolgMinSpinBox->setSuffix(QApplication::translate("MainWindow", "'", nullptr));
        dolgotaCheckBox->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        openErrorListBtn->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\266\321\203\321\200\320\275\320\260\320\273 \320\276\320\261 \320\276\321\210\320\270\320\261\320\272\320\260\321\205", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\202", nullptr));
        diffGradSpinBox->setSuffix(QApplication::translate("MainWindow", "\302\260", nullptr));
        diffMinSpinBox->setSuffix(QApplication::translate("MainWindow", "'", nullptr));
        differentCheckBox->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\213", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\234\320\270\320\275\321\203\321\202\321\213", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\232\321\203\321\200\321\201", nullptr));
        kursGradSpinBox->setSuffix(QApplication::translate("MainWindow", "\302\260", nullptr));
        kursMinSpinBox->setSuffix(QApplication::translate("MainWindow", "'", nullptr));
        kursCheckBox->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        errorButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\320\260\320\267", nullptr));
        continueButton->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\250\320\270\321\200\320\276\321\202\320\260", nullptr));
        shirGradSpinBox->setSuffix(QApplication::translate("MainWindow", "\302\260", nullptr));
        shirGradSpinBox->setPrefix(QString());
        shirMinSpinBox->setSuffix(QApplication::translate("MainWindow", "'", nullptr));
        shirotaCheckBox->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 ", nullptr));
        startBut->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        backButton->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
