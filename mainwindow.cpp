#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_m_pb_newgame_clicked()
{

}

void MainWindow::on_m_pb_records_clicked()
{

}

void MainWindow::on_m_pb_checkin_clicked()
{

}

