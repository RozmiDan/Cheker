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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSpinBox *shirGradSpinBox;
    QSpinBox *shirMinSpinBox;
    QCheckBox *shirotaCheckBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpinBox *dolgGradSpinBox;
    QSpinBox *dolgMinSpinBox;
    QCheckBox *dolgotaCheckBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *kursGradSpinBox;
    QSpinBox *kursMinSpinBox;
    QCheckBox *kursCheckBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpinBox *krenGradSpinBox;
    QSpinBox *krenMinSpinBox;
    QCheckBox *krenCheckBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QSpinBox *diffGradSpinBox;
    QSpinBox *diffMinSpinBox;
    QCheckBox *differentCheckBox;
    QPushButton *errorButton;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QTimeEdit *timeEdit;
    QPushButton *startBut;
    QPushButton *continueButton;
    QPushButton *finishButton;
    QPushButton *openErrorListBtn;
    QWidget *page_2;
    QWidget *layoutWidget1;
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
        MainWindow->resize(256, 414);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 241, 341));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 202, 311));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        shirGradSpinBox = new QSpinBox(layoutWidget);
        shirGradSpinBox->setObjectName(QString::fromUtf8("shirGradSpinBox"));
        shirGradSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        shirGradSpinBox->setReadOnly(true);
        shirGradSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        shirGradSpinBox->setMinimum(-90);
        shirGradSpinBox->setMaximum(90);
        shirGradSpinBox->setValue(-90);

        horizontalLayout_5->addWidget(shirGradSpinBox);

        shirMinSpinBox = new QSpinBox(layoutWidget);
        shirMinSpinBox->setObjectName(QString::fromUtf8("shirMinSpinBox"));
        shirMinSpinBox->setReadOnly(true);
        shirMinSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        shirMinSpinBox->setMaximum(59);

        horizontalLayout_5->addWidget(shirMinSpinBox);

        shirotaCheckBox = new QCheckBox(layoutWidget);
        shirotaCheckBox->setObjectName(QString::fromUtf8("shirotaCheckBox"));
        shirotaCheckBox->setChecked(true);

        horizontalLayout_5->addWidget(shirotaCheckBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        dolgGradSpinBox = new QSpinBox(layoutWidget);
        dolgGradSpinBox->setObjectName(QString::fromUtf8("dolgGradSpinBox"));
        dolgGradSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dolgGradSpinBox->setReadOnly(true);
        dolgGradSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dolgGradSpinBox->setMinimum(-180);
        dolgGradSpinBox->setMaximum(180);
        dolgGradSpinBox->setValue(-180);

        horizontalLayout_4->addWidget(dolgGradSpinBox);

        dolgMinSpinBox = new QSpinBox(layoutWidget);
        dolgMinSpinBox->setObjectName(QString::fromUtf8("dolgMinSpinBox"));
        dolgMinSpinBox->setReadOnly(true);
        dolgMinSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dolgMinSpinBox->setMaximum(59);

        horizontalLayout_4->addWidget(dolgMinSpinBox);

        dolgotaCheckBox = new QCheckBox(layoutWidget);
        dolgotaCheckBox->setObjectName(QString::fromUtf8("dolgotaCheckBox"));
        dolgotaCheckBox->setChecked(false);

        horizontalLayout_4->addWidget(dolgotaCheckBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        kursGradSpinBox = new QSpinBox(layoutWidget);
        kursGradSpinBox->setObjectName(QString::fromUtf8("kursGradSpinBox"));
        kursGradSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        kursGradSpinBox->setReadOnly(true);
        kursGradSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        kursGradSpinBox->setMinimum(0);
        kursGradSpinBox->setMaximum(360);
        kursGradSpinBox->setValue(0);

        horizontalLayout_3->addWidget(kursGradSpinBox);

        kursMinSpinBox = new QSpinBox(layoutWidget);
        kursMinSpinBox->setObjectName(QString::fromUtf8("kursMinSpinBox"));
        kursMinSpinBox->setReadOnly(true);
        kursMinSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        kursMinSpinBox->setMaximum(59);

        horizontalLayout_3->addWidget(kursMinSpinBox);

        kursCheckBox = new QCheckBox(layoutWidget);
        kursCheckBox->setObjectName(QString::fromUtf8("kursCheckBox"));

        horizontalLayout_3->addWidget(kursCheckBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        krenGradSpinBox = new QSpinBox(layoutWidget);
        krenGradSpinBox->setObjectName(QString::fromUtf8("krenGradSpinBox"));
        krenGradSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        krenGradSpinBox->setReadOnly(true);
        krenGradSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        krenGradSpinBox->setMinimum(-90);
        krenGradSpinBox->setMaximum(90);
        krenGradSpinBox->setValue(-90);

        horizontalLayout_2->addWidget(krenGradSpinBox);

        krenMinSpinBox = new QSpinBox(layoutWidget);
        krenMinSpinBox->setObjectName(QString::fromUtf8("krenMinSpinBox"));
        krenMinSpinBox->setReadOnly(true);
        krenMinSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        krenMinSpinBox->setMaximum(59);

        horizontalLayout_2->addWidget(krenMinSpinBox);

        krenCheckBox = new QCheckBox(layoutWidget);
        krenCheckBox->setObjectName(QString::fromUtf8("krenCheckBox"));

        horizontalLayout_2->addWidget(krenCheckBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        diffGradSpinBox = new QSpinBox(layoutWidget);
        diffGradSpinBox->setObjectName(QString::fromUtf8("diffGradSpinBox"));
        diffGradSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        diffGradSpinBox->setReadOnly(true);
        diffGradSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        diffGradSpinBox->setMinimum(-90);
        diffGradSpinBox->setMaximum(90);
        diffGradSpinBox->setValue(-90);

        horizontalLayout->addWidget(diffGradSpinBox);

        diffMinSpinBox = new QSpinBox(layoutWidget);
        diffMinSpinBox->setObjectName(QString::fromUtf8("diffMinSpinBox"));
        diffMinSpinBox->setReadOnly(true);
        diffMinSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        diffMinSpinBox->setMaximum(59);

        horizontalLayout->addWidget(diffMinSpinBox);

        differentCheckBox = new QCheckBox(layoutWidget);
        differentCheckBox->setObjectName(QString::fromUtf8("differentCheckBox"));

        horizontalLayout->addWidget(differentCheckBox);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        errorButton = new QPushButton(layoutWidget);
        errorButton->setObjectName(QString::fromUtf8("errorButton"));

        verticalLayout_2->addWidget(errorButton);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        timeEdit = new QTimeEdit(layoutWidget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_6->addWidget(timeEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);

        startBut = new QPushButton(layoutWidget);
        startBut->setObjectName(QString::fromUtf8("startBut"));
        startBut->setAutoExclusive(false);

        verticalLayout_2->addWidget(startBut);

        continueButton = new QPushButton(layoutWidget);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        continueButton->setAutoExclusive(false);

        verticalLayout_2->addWidget(continueButton);

        finishButton = new QPushButton(layoutWidget);
        finishButton->setObjectName(QString::fromUtf8("finishButton"));
        finishButton->setAutoExclusive(false);

        verticalLayout_2->addWidget(finishButton);

        openErrorListBtn = new QPushButton(layoutWidget);
        openErrorListBtn->setObjectName(QString::fromUtf8("openErrorListBtn"));
        openErrorListBtn->setCheckable(false);
        openErrorListBtn->setAutoExclusive(false);

        verticalLayout_2->addWidget(openErrorListBtn);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        layoutWidget1 = new QWidget(page_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 10, 231, 321));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        displayTextEdit = new QTextEdit(layoutWidget1);
        displayTextEdit->setObjectName(QString::fromUtf8("displayTextEdit"));
        displayTextEdit->setReadOnly(true);

        verticalLayout_3->addWidget(displayTextEdit);

        backButton = new QPushButton(layoutWidget1);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setAutoExclusive(false);

        verticalLayout_3->addWidget(backButton);

        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 256, 21));
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
        label->setText(QApplication::translate("MainWindow", "\320\250\320\270\321\200\320\276\321\202\320\260", nullptr));
        shirGradSpinBox->setSuffix(QApplication::translate("MainWindow", "\302\260", nullptr));
        shirGradSpinBox->setPrefix(QString());
        shirMinSpinBox->setSuffix(QApplication::translate("MainWindow", "'", nullptr));
        shirotaCheckBox->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 ", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\273\320\263\320\276\321\202\320\260", nullptr));
        dolgGradSpinBox->setSuffix(QApplication::translate("MainWindow", "\302\260", nullptr));
        dolgMinSpinBox->setSuffix(QApplication::translate("MainWindow", "'", nullptr));
        dolgotaCheckBox->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\232\321\203\321\200\321\201", nullptr));
        kursGradSpinBox->setSuffix(QApplication::translate("MainWindow", "\302\260", nullptr));
        kursMinSpinBox->setSuffix(QApplication::translate("MainWindow", "'", nullptr));
        kursCheckBox->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\232\321\200\320\265\320\275", nullptr));
        krenGradSpinBox->setSuffix(QApplication::translate("MainWindow", "\302\260", nullptr));
        krenMinSpinBox->setSuffix(QApplication::translate("MainWindow", "'", nullptr));
        krenCheckBox->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\202", nullptr));
        diffGradSpinBox->setSuffix(QApplication::translate("MainWindow", "\302\260", nullptr));
        diffMinSpinBox->setSuffix(QApplication::translate("MainWindow", "'", nullptr));
        differentCheckBox->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        errorButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\320\260\320\267", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        startBut->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        continueButton->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        finishButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        openErrorListBtn->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\266\321\203\321\200\320\275\320\260\320\273 \320\276\320\261 \320\276\321\210\320\270\320\261\320\272\320\260\321\205", nullptr));
        backButton->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
