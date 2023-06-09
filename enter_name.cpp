#include "enter_name.h"
#include "ui_enter_name.h"

Enter_name::Enter_name(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Enter_name)
{
    ui->setupUi(this);
    Create_line();
}

void Enter_name::Create_line()
{


}

Enter_name::~Enter_name()
{
    delete ui;
}

void Enter_name::on_pb_cancel_clicked()
{
   close();
}

bool Enter_name::flag()
{
   return start;
}


void Enter_name::on_pb_ok_clicked()
{
    if (ui->line_player->text()=="")
        ui->lable_note->setText("Введи правильное имя");
    else{
    player_name=ui->line_player->text();
    start=true;
    close();}
}

QString Enter_name::show_name()
{
    return player_name;
}

