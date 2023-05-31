#ifndef RECORDS_H
#define RECORDS_H

#include <QDialog>
#include <QFile>
#include <QTableWidget>
#include <QTableWidgetItem>

namespace Ui {
class Records;
}

class Records : public QDialog
{
    Q_OBJECT

public:
    explicit Records(QWidget *parent = nullptr);
    ~Records();

private:
    Ui::Records *ui;
    

    QFile record_file;
    QTableWidget record_table;
    QTableWidgetItem player_string;
    
    
};

#endif // RECORDS_H
