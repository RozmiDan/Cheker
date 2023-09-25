#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //timer 5sec
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),SLOT(timerEventSlot()));
    timer->setInterval(QuanConst::onePeriod*1000);

    connect(ui->startBut, SIGNAL(clicked()),SLOT(startBtnHandler()));
    connect(ui->openErrorListBtn, SIGNAL(clicked()),SLOT(openListHandler()));
    connect(ui->errorButton,SIGNAL(clicked()),SLOT(writeDataInFile()));
    connect(ui->backButton, SIGNAL(clicked()),SLOT(backBtnHandler()));
    connect(ui->continueButton, SIGNAL(clicked()),SLOT(continueBtnHandler()));
    connect(ui->finishButton, SIGNAL(clicked()),SLOT(finishBtnHandler()));

    assignStartValues();

    ui->continueButton->setEnabled(false);
    ui->finishButton->setEnabled(false);
    ui->openErrorListBtn->setEnabled(true);

    shirotaObj.uiGradReference = ui->shirGradSpinBox;
    shirotaObj.uiMinReference = ui->shirMinSpinBox;
    dolgotaObj.uiGradReference = ui->dolgGradSpinBox;
    dolgotaObj.uiMinReference = ui->dolgMinSpinBox;
    krenObj.uiGradReference = ui->krenGradSpinBox;
    krenObj.uiMinReference = ui->krenMinSpinBox;
    differentObj.uiGradReference = ui->diffGradSpinBox;
    differentObj.uiMinReference = ui->diffMinSpinBox;
    kursObj.uiGradReference = ui->kursGradSpinBox;
    kursObj.uiMinReference = ui->kursMinSpinBox;
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::minFromValue(float value)
{
    float left;
    float fract = modf(value,&left);
    fract = roundf(fract*100)/100;
    if(fract == 1)
        fract = 0;
    float min = round(  fract * 60);
    int result = static_cast<int>(min);
    return qAbs(result);
}

int MainWindow::gradFromValue(float value)
{
    return trunc(roundf(value*100)/100);
}


QPair<int, int> MainWindow::getQuanInGrad(float value)
{
    int grad = gradFromValue(value);
    int min = minFromValue(value);
    return QPair<int, int>(grad, min);
}

void MainWindow::changedData(QSpinBox *grad, QSpinBox *min, QPair<int, int> value)
{
    int fst = value.first;
    int scnd = value.second;

    grad->setValue(fst);
    min->setValue(scnd);
}

void MainWindow::calcCoeff()
{
    long long resWithoutRootLong = -1;
    float resWithoutRootFloat = -1;
    int timeOfProc = (ui->timeEdit->time().hour() * hourToSecCoef) + (ui->timeEdit->time().minute() * minToSecCoef);

//    qDebug() << _numsOfValues * QuanConst::onePeriod;
//    qDebug() << ((_numsOfValues * QuanConst::onePeriod) / timeOfProc);
//    qDebug() << resWithoutRootLong;
//    qDebug() << std::pow(resWithoutRootLong,1./_degree);

    ((_numsOfValues * QuanConst::onePeriod) / timeOfProc) > 1 ? (resWithoutRootLong = (_numsOfValues * QuanConst::onePeriod) / timeOfProc) : (resWithoutRootFloat = (float)(_numsOfValues * (float)QuanConst::onePeriod) / timeOfProc);
    (resWithoutRootLong == -1) ? _incremCoef = std::pow(resWithoutRootFloat,1./_degree) : _incremCoef = std::pow(resWithoutRootLong,1./_degree);
    if(isnan(_incremCoef))
    {
        _incremCoef = 0;
    }
    qDebug() << _incremCoef;
}

void MainWindow::algorithmForMultipleParam()
{
    currentObj->param += _incremCoef;

    if ((currentObj->param > currentObj->uiGradReference->maximum()) && (currentObjIndex+1 != selectedQuant.size()))
    {
        _ostatok = currentObj->param - currentObj->uiGradReference->maximum();
        currentObj->param = currentObj->uiGradReference->minimum() + _ostatok;
        changedData(currentObj->uiGradReference,currentObj->uiMinReference,getQuanInGrad(currentObj->param));
        currentObjIndex += 1;
        currentObj = &selectedQuant[currentObjIndex];
        currentObj->param += _incremCoef;
        changedData(currentObj->uiGradReference,currentObj->uiMinReference,getQuanInGrad(currentObj->param));

        if(!(currentObj->param > currentObj->uiGradReference->maximum()))
        {
            currentObjIndex = 0;
            currentObj = &selectedQuant[currentObjIndex];
        }
        else
        {
            currentObj->param -= _incremCoef;
        }
    }
    else if (currentObjIndex+1 == selectedQuant.size())
    {
        testCompleteProcess();
    }
    else
    {
        changedData(currentObj->uiGradReference,currentObj->uiMinReference,getQuanInGrad(currentObj->param));
    }
}

void MainWindow::algorithmForSingleParam()
{
    currentObj->param += _incremCoef;

    if ((currentObj->param > currentObj->uiGradReference->maximum()))
    {
        testCompleteProcess();
    }
    else
    {
        changedData(currentObj->uiGradReference,currentObj->uiMinReference,getQuanInGrad(currentObj->param));
    }
}

void MainWindow::readDataFromFile()
{
    QFile file(_txtName);
    if(!file.open(QIODevice::Text | QIODevice::ReadWrite))
    {
        QMessageBox::warning(this,"Предупреждение","Начните тестирование");
    }
    QTextStream stream(&file);
    ui->displayTextEdit->setText(stream.readAll());
    file.flush();
    file.close();
}

void MainWindow::writeDataInFile()
{
    QFile file(_txtName);
    if (!file.open(QFile::Append | QIODevice::Text))
    {
       QMessageBox::warning(this,"Предупреждение","Начните тестирование");
       return;
    }
    QTextStream out(&file);
    out << "Error while requesting parameters : \n";
    out << "Shirota: "   << ui->shirGradSpinBox->value() << "." << ui->shirMinSpinBox->value() << "\n";
    out << "Dolgota: "   << ui->dolgGradSpinBox->value() << "." << ui->dolgMinSpinBox->value() << "\n";
    out << "Kurs: "      << ui->kursGradSpinBox->value() << "." << ui->kursMinSpinBox->value() << "\n";
    out << "Kren: "      << ui->krenGradSpinBox->value() << "." << ui->krenMinSpinBox->value() << "\n";
    out << "Different: " << ui->diffGradSpinBox->value() << "." << ui->diffMinSpinBox->value() << "\n\n";

    file.flush();
    file.close();
}

void MainWindow::assignStartValues()
{
    shirotaObj.param   = StartQuanParameters::shirStartParam;
    dolgotaObj.param   = StartQuanParameters::dolgStartParam;
    kursObj.param      = StartQuanParameters::kursStartParam;
    krenObj.param      = StartQuanParameters::krenStartParam;
    differentObj.param = StartQuanParameters::diffStartParam;
}

void MainWindow::assignUiStartValues()
{
    changedData(shirotaObj.uiGradReference,shirotaObj.uiMinReference,getQuanInGrad(StartQuanParameters::shirStartParam));
    changedData(dolgotaObj.uiGradReference,dolgotaObj.uiMinReference,getQuanInGrad(StartQuanParameters::dolgStartParam));
    changedData(kursObj.uiGradReference,kursObj.uiMinReference,getQuanInGrad(StartQuanParameters::kursStartParam));
    changedData(krenObj.uiGradReference,krenObj.uiMinReference,getQuanInGrad(StartQuanParameters::krenStartParam));
    changedData(differentObj.uiGradReference,differentObj.uiMinReference,getQuanInGrad(StartQuanParameters::diffStartParam));
}

void MainWindow::testCompleteProcess()
{
    timer->stop();
    _incremCoef = 0;
    QMessageBox::information(this,"Оповещение","Проверка завершена");
    assignStartValues();
    assignUiStartValues();
    ui->timeEdit->setTime(QTime(00,00));
}

void MainWindow::timerEventSlot()
{
    if(selectedQuant.size() == 1)
    {
        algorithmForSingleParam();
    }

    else
    {
        algorithmForMultipleParam();
    }
}

void MainWindow::startBtnHandler()
{
    _degree = 0;
    _numsOfValues = 1;
    selectedQuant.clear();

    if(ui->shirotaCheckBox->isChecked())
    {
        selectedQuant.append(shirotaObj);
        _degree += 1;
        _numsOfValues *= QuanConst::numOfOptShir;
    }

    if(ui->dolgotaCheckBox->isChecked())
    {
        selectedQuant.append(dolgotaObj);
        _degree += 1;
        _numsOfValues *= QuanConst::numOfOptDolg;
    }

    if(ui->kursCheckBox->isChecked())
    {
        selectedQuant.append(kursObj);
        _degree += 1;
        _numsOfValues *= QuanConst::numOfOptKurs;
    }

    if(ui->krenCheckBox->isChecked())
    {
        selectedQuant.append(krenObj);
        _degree += 1;
        _numsOfValues *= QuanConst::numOfOptKren;
    }

    if(ui->differentCheckBox->isChecked())
    {
        selectedQuant.append(differentObj);
        _degree += 1;
        _numsOfValues *= QuanConst::numOfOptDiff;
    }

    if (ui->timeEdit->time().hour()==0 && ui->timeEdit->time().minute() == 0)
    {
        QMessageBox::warning(this, "Ошибка", "Введите время тестирования");
    }

    else if(_degree == 0)
    {
        QMessageBox::warning(this,"Ошибка","Выберите измеряемые параметры!");
    }



    else
    {
        timer->start();
        calcCoeff();
        if(_incremCoef == 0)
        {
            timer->stop();
            QMessageBox::critical(this,"Ошибка","Недостаточный промежуток времени");
    //        assignStartValues();
    //        assignUiStartValues();
            ui->timeEdit->setTime(QTime(00,00));
            return;
        }
        currentObjIndex = 0;
        currentObj = &selectedQuant[currentObjIndex];
        _txtName = "test" + (QDateTime::currentDateTime().toString("dd.MM.yy hh-mm-ss")) + ".txt";


        ui->startBut->setEnabled(false);
        ui->finishButton->setEnabled(true);
        ui->continueButton->setEnabled(false);
        ui->openErrorListBtn->setEnabled(true);
    }
}

void MainWindow::openListHandler()
{
    if(timer->isActive())
    {
        timer->stop();
    }
    ui->stackedWidget->setCurrentIndex(1);
    readDataFromFile();
}

void MainWindow::backBtnHandler()
{
    if(_incremCoef > 0)
    {
        ui->startBut->setEnabled(false);
        ui->continueButton->setEnabled(true);
        ui->finishButton->setEnabled(true);
        ui->openErrorListBtn->setEnabled(true);
    }

    else if (_incremCoef == 0)
    {
        ui->startBut->setEnabled(true);
        ui->continueButton->setEnabled(false);
        ui->finishButton->setEnabled(false);
        ui->openErrorListBtn->setEnabled(true);
    }

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::continueBtnHandler()
{
    timer->start();

    ui->startBut->setEnabled(false);
    ui->finishButton->setEnabled(true);
    ui->continueButton->setEnabled(false);
    ui->openErrorListBtn->setEnabled(true);
}

void MainWindow::finishBtnHandler()
{
    testCompleteProcess();

    ui->startBut->setEnabled(true);
    ui->finishButton->setEnabled(false);
    ui->continueButton->setEnabled(false);
    ui->openErrorListBtn->setEnabled(true);
}
