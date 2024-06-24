#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QWidget>
#include "widget.h"

namespace Ui {
class editdialog;
}

class editdialog : public QWidget
{
    Q_OBJECT

public:
    explicit editdialog(QWidget *parent = nullptr,QString Name="",QString Telephone="",QString Address="");
    ~editdialog();

private:
    Ui::editdialog *ui;
};

#endif // EDIT_H
