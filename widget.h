#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "person.h"
#include "persontable.h"
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void Addperson(QString Name,QString Telephone,QString Address);
    void new_build();
    void Del();
    void edit_mess(QString Name,QString Telephone,QString Address);
    void changedialog();
    void search(QString s);
    void savetofile();

private slots:
    void on_addButton_clicked();

    void on_editButton_clicked();

    void on_Widget_customContextMenuRequested(const QPoint &pos);

    void on_saveButton_2_clicked();

private:
    Ui::Widget *ui;
    persontable Table1;
};
#endif // WIDGET_H
