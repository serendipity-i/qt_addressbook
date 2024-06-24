#include "changedialog.h"
#include "ui_changedialog.h"
#include <QMessageBox>

changedialog::changedialog(QWidget *parent,QString Name,QString Telephone,QString Address) :
    QWidget(parent),
    ui(new Ui::changedialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Show and Edit");
        ui->lineEdit->setText(Name);
        ui->lineEdit_2->setText(Telephone);
        ui->lineEdit_3->setText(Address);
        connect(ui->cancelButton,&QPushButton::clicked,this,&changedialog::close);

        Widget *widgetParent = qobject_cast<Widget*>(parent);
            if (widgetParent) {
        connect(ui->deleteButton,&QPushButton::clicked,parent,[=](){
            widgetParent->Del();
            Widget *fater = new Widget();
                this->close();
            fater->show();
        });
        connect(ui->saveButton,&QPushButton::clicked,parent,[=](){
                QString Name1;
                QString Telephone1;
                QString Address1;
                Name1= ui->lineEdit->text();
                Telephone1=ui->lineEdit_2->text();
                if(Telephone1.size()!=11&&Telephone1.size()!=8)
                {
                    QMessageBox::warning(this,"Error!","The Phine Number Must Be 11 or 8 Digits");
                    return;
                }

                Address1=ui->lineEdit_3->text();
                        widgetParent->edit_mess(Name1,Telephone1,Address1);
                        this->close();
                    });
    }
}

changedialog::~changedialog()
{
    delete ui;
}
