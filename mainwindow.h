#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QSpinBox>
#include <QTimer>
#include <QDateTime>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>

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
    void assignStartValues();
    void assignUiStartValues();
    void testCompleteProcess();
    void initFunction();
    void windowState(int state);

    void writeDataToJson();
    int readDatafromJson();
    void readDataFromFile();

private slots:
    void writeDataInFile();
    void timerEventSlot();
    void startBtnHandler();
    void openListHandler();
    void backBtnHandler();
    void continueBtnHandler();
    void finishBtnHandler();
    void loadInfoFromJson();
    void saveInfoInJson();

private:
    Ui::MainWindow *ui;

    QString _txtName;
    int _winStateVar;
    QTimer *_timer = nullptr;

    //For calcuting value
    float _ostatok = 0;
    float _incremCoef = 0;
    long long _numsOfValues = 1;
    qint8 _degree = 0;

    //For algorythm
    QuantParametrs _shirotaObj;
    QuantParametrs _dolgotaObj;
    QuantParametrs _krenObj;
    QuantParametrs _differentObj;
    QuantParametrs _kursObj;
    QuantParametrs *_currentObj = nullptr;
    int _currentObjIndex;
    QVector <QuantParametrs*> _selectedQuant;

    //For JSON
    QFile _fileJSON;
    QJsonDocument _doc;
    QJsonArray _docArr;
    QString _globalPath = ".\\..\\ty\\savedata.json";
    QJsonParseError _parsErr;

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
