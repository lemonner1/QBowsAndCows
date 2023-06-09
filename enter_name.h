#ifndef ENTER_NAME_H
#define ENTER_NAME_H

#include <QDialog>


namespace Ui {
class Enter_name;
}

class Enter_name : public QDialog
{
    Q_OBJECT

public:
    explicit Enter_name(QWidget *parent = nullptr);
    ~Enter_name();

    QString show_name();

    bool flag();
    QString player_name;

private slots:
    void on_pb_cancel_clicked();

    void on_pb_ok_clicked();

    void Create_line();


private:
    Ui::Enter_name *ui;

    bool start;
};

#endif // ENTER_NAME_H
