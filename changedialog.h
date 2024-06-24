#ifndef CHANGEDIALOG_H
#define CHANGEDIALOG_H

#include <QWidget>
#include "widget.h"


namespace Ui {
class changedialog;
}

class changedialog : public QWidget
{
    Q_OBJECT

public:
    explicit changedialog(QWidget *parent,QString Name,QString Telephone,QString Address);
    ~changedialog();

public:
    Ui::changedialog *ui;
};

#endif // CHANGEDIALOG_H
