#include "new_build.h"
#include "ui_new_build.h"
#include <QMessageBox>

new_build::new_build(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::new_build)
{
    ui->setupUi(this);
     this->setWindowTitle("Add Contact");
    connect(ui->cancelButton,&QPushButton::clicked,this,&new_build::close);
    Widget *widgetParent = qobject_cast<Widget*>(parent);
        if (widgetParent) {
    connect(ui->saveButton,&QPushButton::clicked,parent,[=](){
                    QString Name;
                    QString Telephone;
                    QString Address;
                    Name= ui->lineEdit->text();
                    Telephone=ui->lineEdit_2->text();
                    if(Telephone.size()!=11&&Telephone.size()!=8)
                    {
                        QMessageBox::warning(this,"Error!","The Phine Number Must Be 11 or 8 Digits");
                        return;
                    }

                    Address=ui->lineEdit_3->text();
                    widgetParent->Addperson(Name,Telephone,Address);
                    this->close();
   });
}
}

new_build::~new_build()
{
    delete ui;
}



void new_build::on_backButton_clicked()
{
    Widget *fater = new Widget();
    this->close();
    fater->show();
}

