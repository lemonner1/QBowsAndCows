#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QRegularExpression>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QByteArray>
#include <QValidator>
#include "enter_name.h"
#include "records.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_new_game_clicked();

    void on_pb_records_clicked();

    void on_pb_check_clicked();

    void count();

    void print_file();

private:
    Ui::MainWindow *ui;
    Enter_name* name;
    Records* rec;

    int goal;
    int count_cow;
    int count_bull;
    int rows=0;

    QString name_player;
    QFile record_file;
    QTableWidget record_table;
    QTableWidgetItem player_string;
};
#endif // MAINWINDOW_H
