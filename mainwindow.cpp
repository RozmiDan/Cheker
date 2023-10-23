#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initFunction();
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
    int timeOfProc = (ui->hoursBox->value() * hourToSecCoef) + (ui->minutesBox->value() * minToSecCoef);

    ((_numsOfValues * QuanConst::onePeriod) / timeOfProc) > 1 ? (resWithoutRootLong = (_numsOfValues * QuanConst::onePeriod) / timeOfProc) :
                                                                (resWithoutRootFloat = static_cast<float>(_numsOfValues * QuanConst::onePeriod) / timeOfProc);
    (resWithoutRootLong == -1) ? _incremCoef = static_cast<float>(std::pow(resWithoutRootFloat,1./_degree)) : _incremCoef = static_cast<float>(std::pow(resWithoutRootLong,1./_degree));
    if(isnan(_incremCoef))
    {
        _incremCoef = 0;
    }
    qDebug() << _incremCoef;
}

void MainWindow::algorithmForMultipleParam()
{
    _currentObj->param += _incremCoef;

    if ((_currentObj->param > _currentObj->uiGradReference->maximum()) && (_currentObjIndex+1 != _selectedQuant.size()))
    {
        _ostatok = _currentObj->param - _currentObj->uiGradReference->maximum();
        _currentObj->param = _currentObj->uiGradReference->minimum() + _ostatok;
        changedData(_currentObj->uiGradReference,_currentObj->uiMinReference,getQuanInGrad(_currentObj->param));
        _currentObjIndex += 1;
        _currentObj = _selectedQuant[_currentObjIndex];
        _currentObj->param += _incremCoef;
        changedData(_currentObj->uiGradReference,_currentObj->uiMinReference,getQuanInGrad(_currentObj->param));

        if(!(_currentObj->param > _currentObj->uiGradReference->maximum()))
        {
            _currentObjIndex = 0;
            _currentObj = _selectedQuant[_currentObjIndex];
        }
        else
        {
            _currentObj->param -= _incremCoef;
        }
    }
    else if (_currentObjIndex+1 == _selectedQuant.size())
    {
        testCompleteProcess();
    }
    else
    {
        changedData(_currentObj->uiGradReference,_currentObj->uiMinReference,getQuanInGrad(_currentObj->param));
    }
}

void MainWindow::algorithmForSingleParam()
{
    _currentObj->param += _incremCoef;

    if ((_currentObj->param > _currentObj->uiGradReference->maximum()))
    {
        testCompleteProcess();
    }
    else
    {
        changedData(_currentObj->uiGradReference,_currentObj->uiMinReference,getQuanInGrad(_currentObj->param));
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

    out << "Shirota: "   << _shirotaObj.param << "\n";
    out << "Dolgota: "   << _dolgotaObj.param << "\n";
    out << "Kurs: "      << _kursObj.param << "\n";
    out << "Kren: "      << _krenObj.param << "\n";
    out << "Different: " << _differentObj.param << "\n\n";

    file.flush();
    file.close();
}

void MainWindow::assignStartValues()
{
    _shirotaObj.param   = StartQuanParameters::shirStartParam;
    _dolgotaObj.param   = StartQuanParameters::dolgStartParam;
    _kursObj.param      = StartQuanParameters::kursStartParam;
    _krenObj.param      = StartQuanParameters::krenStartParam;
    _differentObj.param = StartQuanParameters::diffStartParam;
}

void MainWindow::assignUiStartValues()
{
    changedData(_shirotaObj.uiGradReference,_shirotaObj.uiMinReference,getQuanInGrad(StartQuanParameters::shirStartParam));
    changedData(_dolgotaObj.uiGradReference,_dolgotaObj.uiMinReference,getQuanInGrad(StartQuanParameters::dolgStartParam));
    changedData(_kursObj.uiGradReference,_kursObj.uiMinReference,getQuanInGrad(StartQuanParameters::kursStartParam));
    changedData(_krenObj.uiGradReference,_krenObj.uiMinReference,getQuanInGrad(StartQuanParameters::krenStartParam));
    changedData(_differentObj.uiGradReference,_differentObj.uiMinReference,getQuanInGrad(StartQuanParameters::diffStartParam));
}

void MainWindow::testCompleteProcess()
{
     ui->progressBar->setValue(_selectedQuant[_selectedQuant.size()-1]->uiGradReference->maximum());

    _timer->stop();
    _incremCoef = 0;
    QMessageBox::information(this,"Оповещение","Проверка завершена");
    assignStartValues();
    assignUiStartValues();
    ui->hoursBox->setValue(0);
    ui->minutesBox->setValue(0);
    ui->progressBar->setValue(_selectedQuant[_selectedQuant.size()-1]->uiGradReference->minimum());

    _winStateVar = 0;
    windowState(_winStateVar);
}

void MainWindow::initFunction()
{
    _timer = new QTimer(this);
    connect(_timer,SIGNAL(timeout()),SLOT(timerEventSlot()));
    _timer->setInterval(QuanConst::onePeriod*1000);

    connect(ui->startBut, SIGNAL(clicked()),SLOT(startBtnHandler()));
    connect(ui->openErrorListBtn, SIGNAL(clicked()),SLOT(openListHandler()));
    connect(ui->errorButton,SIGNAL(clicked()),SLOT(writeDataInFile()));
    connect(ui->backButton, SIGNAL(clicked()),SLOT(backBtnHandler()));
    connect(ui->continueButton, SIGNAL(clicked()),SLOT(continueBtnHandler()));
    connect(ui->finishButton, SIGNAL(clicked()),SLOT(finishBtnHandler()));
    connect(ui->loadInfoButt, SIGNAL(clicked()),SLOT(loadInfoFromJson()));
    connect(ui->saveInfoButt, SIGNAL(clicked()),SLOT(saveInfoInJson()));

    assignStartValues();

    _winStateVar = 0;
    windowState(_winStateVar);

    _shirotaObj.uiGradReference = ui->shirGradSpinBox;
    _shirotaObj.uiMinReference = ui->shirMinSpinBox;
    _dolgotaObj.uiGradReference = ui->dolgGradSpinBox;
    _dolgotaObj.uiMinReference = ui->dolgMinSpinBox;
    _krenObj.uiGradReference = ui->krenGradSpinBox;
    _krenObj.uiMinReference = ui->krenMinSpinBox;
    _differentObj.uiGradReference = ui->diffGradSpinBox;
    _differentObj.uiMinReference = ui->diffMinSpinBox;
    _kursObj.uiGradReference = ui->kursGradSpinBox;
    _kursObj.uiMinReference = ui->kursMinSpinBox;

    _fileJSON.setFileName(_globalPath);
}

void MainWindow::windowState(int state)
{
    switch (state)
    {
        case(0): // Start and Finish window
        {
            ui->startBut->setEnabled(true);
            ui->finishButton->setEnabled(false);
            ui->continueButton->setEnabled(false);
            ui->openErrorListBtn->setEnabled(true);
            ui->saveInfoButt->setEnabled(false);
            ui->loadInfoButt->setEnabled(true);
            break;
        }

        case(1): // Window is in proc
        {
            ui->startBut->setEnabled(false);
            ui->finishButton->setEnabled(true);
            ui->continueButton->setEnabled(false);
            ui->openErrorListBtn->setEnabled(true);
            ui->saveInfoButt->setEnabled(true);
            ui->loadInfoButt->setEnabled(false);
            break;
        }

        case(2): // Window after backbut
        {
            ui->startBut->setEnabled(false);
            ui->finishButton->setEnabled(true);
            ui->continueButton->setEnabled(true);
            ui->openErrorListBtn->setEnabled(true);
            ui->saveInfoButt->setEnabled(false);
            ui->loadInfoButt->setEnabled(false);
            break;
        }
        case(3):
        {
            ui->startBut->setEnabled(false);
            ui->finishButton->setEnabled(true);
            ui->continueButton->setEnabled(true);
            ui->openErrorListBtn->setEnabled(true);
            ui->saveInfoButt->setEnabled(true);
            ui->loadInfoButt->setEnabled(false);
            break;
        }
        case(4):
        {
            ui->startBut->setEnabled(false);
            ui->finishButton->setEnabled(true);
            ui->continueButton->setEnabled(true);
            ui->openErrorListBtn->setEnabled(true);
            ui->saveInfoButt->setEnabled(false);
            ui->loadInfoButt->setEnabled(true);
        }
    }
}

void MainWindow::writeDataToJson()
{
    if(_fileJSON.open(QIODevice::WriteOnly))
    {
        QVariantMap map;
        map.insert("incremKoef", _incremCoef);
        map.insert("shirParam", _shirotaObj.param);
        map.insert("dolgParam", _dolgotaObj.param);
        map.insert("kursParam", _kursObj.param);
        map.insert("krenParam", _krenObj.param);
        map.insert("diffParam", _differentObj.param);

        QStringList arr{"0","0","0","0","0"};
        if(ui->shirotaCheckBox->isChecked())
            arr[0] = "1";
        if(ui->dolgotaCheckBox->isChecked())
            arr[1] = "1";
        if(ui->kursCheckBox->isChecked())
            arr[2] = "1";
        if(ui->krenCheckBox->isChecked())
            arr[3] = "1";
        if(ui->differentCheckBox->isChecked())
            arr[4] = "1";

        map.insert("array",QJsonArray::fromStringList(arr));
        QJsonObject json = QJsonObject::fromVariantMap(map);
        _doc.setObject(json);
        _fileJSON.write(_doc.toJson());
        _fileJSON.close();
    }
    else
    {
        QMessageBox::warning(this, "Ошибка","Файл не был открыт");
    }
}

int MainWindow::readDatafromJson()
{
    if(_fileJSON.open(QIODevice::ReadOnly | QFile::Text))
    {
        _doc = QJsonDocument::fromJson(QByteArray(_fileJSON.readAll()), &_parsErr);
    }
    _fileJSON.close();

    if(_fileJSON.size() == 0)
    {
        QMessageBox::warning(this, "Ошибка", "Сохренений не обнаружено");
        return 0;
    }

    _shirotaObj.param = static_cast<float>(_doc.object().value("shirParam").toDouble());
    _dolgotaObj.param = static_cast<float>(_doc.object().value("dolgParam").toDouble());
    _kursObj.param = static_cast<float>(_doc.object().value("kursParam").toDouble());
    _krenObj.param = static_cast<float>(_doc.object().value("krenParam").toDouble());
    _differentObj.param = static_cast<float>(_doc.object().value("diffParam").toDouble());
    _incremCoef = static_cast<float>(_doc.object().value("incremKoef").toDouble());

    _docArr = QJsonValue(_doc.object().value("array")).toArray();
    if(_docArr[0] == "1")
    {
        ui->shirotaCheckBox->setChecked(true);
        _selectedQuant.append(&_shirotaObj);
    }

    if(_docArr[1] == "1")
    {
        ui->dolgotaCheckBox->setChecked(true);
        _selectedQuant.append(&_dolgotaObj);
    }

    if(_docArr[2] == "1")
    {
        ui->kursCheckBox->setChecked(true);
        _selectedQuant.append(&_kursObj);
    }

    if(_docArr[3] == "1")
    {
        ui->krenCheckBox->setChecked(true);
        _selectedQuant.append(&_krenObj);
    }

    if(_docArr[4] == "1")
    {
        ui->differentCheckBox->setChecked(true);
        _selectedQuant.append(&_differentObj);
    }
    return 1;
}

void MainWindow::timerEventSlot()
{
    if(_selectedQuant.size() == 1)
    {
        algorithmForSingleParam();
    }

    else
    {
        algorithmForMultipleParam();
    }

    ui->progressBar->setValue(_selectedQuant[_selectedQuant.size()-1]->param);
}

void MainWindow::startBtnHandler()
{
    _degree = 0;
    _numsOfValues = 1;
    _selectedQuant.clear();

    if(ui->shirotaCheckBox->isChecked())
    {
        _selectedQuant.append(&_shirotaObj);
        _degree += 1;
        _numsOfValues *= QuanConst::numOfOptShir;
    }

    if(ui->dolgotaCheckBox->isChecked())
    {
        _selectedQuant.append(&_dolgotaObj);
        _degree += 1;
        _numsOfValues *= QuanConst::numOfOptDolg;
    }

    if(ui->kursCheckBox->isChecked())
    {
        _selectedQuant.append(&_kursObj);
        _degree += 1;
        _numsOfValues *= QuanConst::numOfOptKurs;
    }

    if(ui->krenCheckBox->isChecked())
    {
        _selectedQuant.append(&_krenObj);
        _degree += 1;
        _numsOfValues *= QuanConst::numOfOptKren;
    }

    if(ui->differentCheckBox->isChecked())
    {
        _selectedQuant.append(&_differentObj);
        _degree += 1;
        _numsOfValues *= QuanConst::numOfOptDiff;
    }

    if (ui->hoursBox->value()==0 && ui->minutesBox->value() == 0)
    {
        QMessageBox::warning(this, "Ошибка", "Введите время тестирования");
    }

    else if(_degree == 0)
    {
        QMessageBox::warning(this,"Ошибка","Выберите измеряемые параметры!");
    }

    else
    {
        _timer->start();
        calcCoeff();
        if(_incremCoef == 0)
        {
            _timer->stop();
            QMessageBox::critical(this,"Ошибка","Недостаточный промежуток времени");
            ui->hoursBox->setValue(0);
            ui->minutesBox->setValue(0);
            return;
        }
        _currentObjIndex = 0;
        _currentObj = _selectedQuant[_currentObjIndex];
        _txtName = "test" + (QDateTime::currentDateTime().toString("dd.MM.yy hh-mm-ss")) + ".txt";

        ui->progressBar->setRange(_selectedQuant[_selectedQuant.size()-1]->uiGradReference->minimum(),_selectedQuant[_selectedQuant.size()-1]->uiGradReference->maximum());
        ui->progressBar->setValue(_selectedQuant[_selectedQuant.size()-1]->uiGradReference->minimum());

        _winStateVar = 1;
        windowState(_winStateVar);
    }
}

void MainWindow::openListHandler()
{
    if(_timer->isActive())
    {
        _timer->stop();
    }
    ui->stackedWidget->setCurrentIndex(1);
    readDataFromFile();
}

void MainWindow::backBtnHandler()
{
    if(_incremCoef > 0)
    {
        _winStateVar = 2;
        windowState(_winStateVar);
    }

    else if (_incremCoef == 0)
    {
        _winStateVar = 0;
        windowState(_winStateVar);
    }

    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::continueBtnHandler()
{
    _timer->start();
    _winStateVar = 1;
    windowState(_winStateVar);
}

void MainWindow::finishBtnHandler()
{
    testCompleteProcess();

    _winStateVar = 0;
    windowState(_winStateVar);
}

void MainWindow::loadInfoFromJson()
{
    ui->shirotaCheckBox->setCheckState(Qt::CheckState::Unchecked);
    ui->dolgotaCheckBox->setCheckState(Qt::CheckState::Unchecked);
    ui->kursCheckBox->setCheckState(Qt::CheckState::Unchecked);
    ui->krenCheckBox->setCheckState(Qt::CheckState::Unchecked);
    ui->differentCheckBox->setCheckState(Qt::CheckState::Unchecked);

    if(_selectedQuant.size() != 0)
        _selectedQuant.clear();
    if(readDatafromJson() == 0)
        return;
    _currentObjIndex = 0;
    _currentObj = _selectedQuant[_currentObjIndex];

    _txtName = "test" + (QDateTime::currentDateTime().toString("dd.MM.yy hh-mm-ss")) + ".txt";

    changedData(_shirotaObj.uiGradReference,_shirotaObj.uiMinReference,getQuanInGrad(_shirotaObj.param));
    changedData(_dolgotaObj.uiGradReference,_dolgotaObj.uiMinReference,getQuanInGrad(_dolgotaObj.param));
    changedData(_kursObj.uiGradReference,_kursObj.uiMinReference,getQuanInGrad(_kursObj.param));
    changedData(_krenObj.uiGradReference,_krenObj.uiMinReference,getQuanInGrad(_krenObj.param));
    changedData(_differentObj.uiGradReference,_differentObj.uiMinReference,getQuanInGrad(_differentObj.param));

    _winStateVar = 3;
    windowState(_winStateVar);

    ui->progressBar->setRange(_selectedQuant[_selectedQuant.size()-1]->uiGradReference->minimum(),_selectedQuant[_selectedQuant.size()-1]->uiGradReference->maximum());
    ui->progressBar->setValue(_selectedQuant[_selectedQuant.size()-1]->param);
}

void MainWindow::saveInfoInJson()
{
    _timer->stop();
    writeDataToJson();

    _winStateVar = 4;
    windowState(_winStateVar);
}
