#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions.cpp"
#include <complex>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QColor("white"));
    scene->addLine(1,1,1,1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::complex<double>zBegin = prosessComplex(ui->lineEdit->text());
    std::complex<double>aMult  = prosessComplex(ui->lineEdit_2->text());
    std::complex<double>cAdd   = prosessComplex(ui->lineEdit_3->text());
    std::complex<double> lastPoint = zBegin;
    int N = 1000;
    while(N--){
        scene->addLine(lastPoint.real(),lastPoint.imag(),lastPoint.real(),lastPoint.imag());
        lastPoint = lastPoint*aMult + cAdd;
        qDebug() << lastPoint.real() <<lastPoint.imag();
    }
}

