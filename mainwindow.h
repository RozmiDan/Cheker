#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QSpinBox>
#include <QTimer>
#include <QDateTime>

namespace Ui {
class MainWindow;
}

struct QuantParametrs
{
    QSpinBox* uiGradReference = nullptr;
    QSpinBox* uiMinReference = nullptr;
    float param;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int minFromValue(float value);
    int gradFromValue(float value);

    QPair<int,int> getQuanInGrad(float value);
    void changedData(QSpinBox* grad, QSpinBox* min, QPair<int,int> value);
    void calcCoeff();
    void algorithmForMultipleParam();
    void algorithmForSingleParam();
    void readDataFromFile();
    void assignStartValues();
    void assignUiStartValues();
    void testCompleteProcess();

private slots:
    void writeDataInFile();
    void timerEventSlot();
    void startBtnHandler();
    void openListHandler();
    void backBtnHandler();
    void continueBtnHandler();
    void finishBtnHandler();

private:
    Ui::MainWindow *ui;

    float _ostatok = 0;

    float _incremCoef = 0;
    long long _numsOfValues = 1;
    qint8 _degree = 0;

    QString _txtName;

    QuantParametrs shirotaObj;
    QuantParametrs dolgotaObj;
    QuantParametrs krenObj;
    QuantParametrs differentObj;
    QuantParametrs kursObj;
    QuantParametrs *currentObj = nullptr;

    int currentObjIndex;

    QVector <QuantParametrs> selectedQuant;

    QTimer *timer = nullptr;

    enum StartQuanParameters
    {
        shirStartParam = -90,
        dolgStartParam = -180,
        kursStartParam = 0,
        krenStartParam = -90,
        diffStartParam = -90,
    };

    enum QuanConst
    {
        numOfOptShir = 180,
        numOfOptDolg = 360,
        numOfOptKren = 180,
        numOfOptDiff = 180,
        numOfOptKurs = 360,
        onePeriod = 5,
        hourToSecCoef = 3600,
        minToSecCoef = 60
    };
};

#endif // MAINWINDOW_H
