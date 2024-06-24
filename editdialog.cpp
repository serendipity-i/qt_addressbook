#include "editdialog.h"
#include "ui_editdialog.h"
#include <QMessageBox>

editdialog::editdialog(QWidget *parent,QString Name,QString Telephone,QString Address):
    QWidget(parent),
    ui(new Ui::editdialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Show and Edit");
    ui->lineEdit->setText(Name);
    ui->lineEdit_2->setText(Telephone);
    ui->lineEdit_3->setText(Address);
    connect(ui->cancelButton,&QPushButton::clicked,this,&editdialog::close);

    Widget *widgetParent = qobject_cast<Widget*>(parent);
        if (widgetParent) {
    connect(ui->deleteButton,&QPushButton::clicked,parent,[=](){
        widgetParent->Del();
            this->close();
    });
    connect(ui->saveButton,&QPushButton::clicked,parent,[=](){
            QString Name1;
            QString Telephone1;
            QString Address1;
            Name1= ui->lineEdit->text();
            Telephone1=ui->lineEdit_2->text();
            Address1=ui->lineEdit_3->text();
                    widgetParent->edit_mess(Name1,Telephone1,Address1);
                    this->close();
                });
}
}

editdialog::~editdialog()
{
    delete ui;
}
