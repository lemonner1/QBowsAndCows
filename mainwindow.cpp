#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_main->setColumnCount(2);
    ui->table_main->setRowCount(rows);
    ui->table_main->setShowGrid(true);
    ui->table_main->setHorizontalHeaderLabels(QStringList()<<"Число"<<"Результат");
    ui->table_main->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->pb_check->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^([1-9])(?!\\1)([0-9])(?!\\1|\\2)([0-9])(?!\\1|\\2|\\3)([0-9])$"),this));
}


void MainWindow::print_file(){
    QFile record_file("record.txt");
    if (!record_file.open(QIODevice::ReadWrite))
    {
        ui->label_2->setText("file not open");
        return;
    }
    QByteArray fileData;
    fileData=record_file.readAll();
    QString tmp;
    while (!record_file.atEnd())
    {
        QTextStream in(&record_file);
        in >> tmp;
        if (tmp == name_player)
        {
            in >> tmp;
        }
    }
    record_file.close();
}
MainWindow::~MainWindow()
{
    delete ui;
}

bool IsGood (int numb)
{
    int a1=numb%10;
    int a2=(numb%100)/10;
    int a3=(numb/100)%10;
    int a4=numb/1000;
    if (a1 != a2 && a1!=a3 && a1!=a4)
        if (a2!=a3 && a2!=a4)
            if (a3!=a4)
                return true;
    return false;
}

void MainWindow::on_pb_new_game_clicked()
{
    name=new Enter_name;
    name->exec();
    if (name->flag()==true)
    {   ui->pb_check->setEnabled(true);
        ui->lineEdit->setEnabled(true);
        ui->label->setText("Попробуй угадать");
        bool is_numb=false;
        name_player=name->player_name;
        while (is_numb==false)
        {
            goal=rand()%8999+1000;
            if (IsGood(goal)==true)
               is_numb=true;

        }


    }

}

void MainWindow::on_pb_records_clicked()
{
    rec=new Records;
    rec->show();
}

void MainWindow::on_pb_check_clicked()
{

    if( ui->lineEdit->text().length()!=4)
        ui->label->setText("Введи правильное число");
    else
    {

    ui->table_main->setRowCount(rows+1);
    count();
    QTableWidgetItem *tab_Item2 = new QTableWidgetItem();
    QTableWidgetItem *tab_Item3 = new QTableWidgetItem();
    tab_Item2->setText(ui->lineEdit->text());
    tab_Item3->setText("Cows: "+QString::number(count_cow)+" "+"Bulls: "+QString::number(count_bull));
    ui->table_main->setItem(rows,0,tab_Item2);
    ui->table_main->setItem(rows,1,tab_Item3);
    rows++;
    if (count_bull==4)
    {
        ui->label->setText("Приветствую вас, чемпион");
        ui->pb_check->setEnabled(false);
        ui->lineEdit->setEnabled(false);
        print_file();
    }
}

}

void MainWindow::count()
{
    QString tmp = ui->lineEdit->text();
    QString goal_string =QString::number(goal);
    count_bull=0;
    count_cow=0;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            if (tmp[i]==goal_string[j])
               { if (i==j)
                    ++count_bull;
                else
                    ++count_cow;}
        }
    }
    std::cout<<count_bull<<" bull||   "<<count_cow<<" cows ||   "<<goal<<std::endl;
}
