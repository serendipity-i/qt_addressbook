#include "widget.h"
#include "ui_widget.h"
#include "person.h"
#include "persontable.h"
#include "changedialog.h"
#include "new_build.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFile>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Adderss List");
    QFile file("/home/ICer/Work/address/input.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,tr("ERROR!"),
                tr("error").arg(file.errorString()));
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line=in.readLine();
        QStringList a=line.split(" ");
        QString Name=a.at(0);
        QString Telephone=a.at(1);
        QString Address=a.at(2);
         Addperson(Name,Telephone,Address);
    }
    file.close();
    connect(ui->addButton,&QPushButton::clicked,this,&Widget::new_build);
    connect(ui->Search,&QPushButton::clicked,this,[=](){
            QString s=ui->lineEdit->text();
              search(s);
        });
    connect(ui->cancelButton,&QPushButton::clicked,this,[=](){
              ui->lineEdit->clear();
              ui->listWidget->clear();
              for(int i=0;i<Table1.getmax();i++)
              {
                  QListWidgetItem *item=new QListWidgetItem(Table1.table[i].getname());
                   ui->listWidget->addItem(item);
              }
        });
    connect(ui->editButton,&QPushButton::clicked,this,&Widget::changedialog);


    connect(ui->deleteButton,&QPushButton::clicked,this,&Widget::Del);
    connect(ui->saveButton,&QPushButton::clicked,this,&Widget::savetofile);
}


Widget::~Widget()
{
    delete ui;
}

void Widget::savetofile()
{
    QFile file2("/home/ICer/Work/address/output.txt");
    if(!file2.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,tr("ERROR!"),
                tr("error").arg(file2.errorString()));
    return;
    }
    QTextStream out(&file2);
    for(int i=0; i < Table1.getmax(); i++)
    {
       out << Table1.table[i].getname() << ""
           << Table1.table[i].gettel() << ""
           << Table1.table[i].getadd() << "\n";
    }
    QMessageBox::information(this,"Success","AddressBook Information was Successfully Exported!");
    file2.close();

}

void Widget::search(QString s)//综合查询函数，自动判别用户输入的是姓名还是电话还是地址，并进行查询
{
    int j=0;
    bool tag=false;
     while(j<Table1.getmax())//按名字查询
     {
          QListWidgetItem* item = ui->listWidget->takeItem(0);
          QString a=item->text();
         if(a.indexOf(s)>=0)//如果包含用户输入的字符串，则代表找到了
         {
              ui->listWidget->addItem(item);
              tag=true;
         }
         else
         {

         }
         j++;
     }
     if(tag)return;//如果找到了，不再继续查询

     for(int i=0;i<Table1.getmax();i++)
     {
         QListWidgetItem *item=new QListWidgetItem(Table1.table[i].getname());
          ui->listWidget->addItem(item);
     }
     j=0;
     while(j<Table1.getmax())//按电话号码查询
     {
          QListWidgetItem* item = ui->listWidget->takeItem(0);
          QString name=item->text();
          person p;
          for(int i=0;i<Table1.getmax();i++)
          {
              if(Table1.table[i].getname()==name)
              {
                   p=Table1.table[i];
              }
          }
          QString a=p.gettel();
         if(a.indexOf(s)>=0)//如果包含用户输入的字符串，则代表找到了
         {
             item->setText(p.getname()+"("+p.gettel()+")");
              ui->listWidget->addItem(item);
              tag=true;
         }
         else
         {

         }
         j++;
     }
      if(tag)return;//如果找到了，不再继续查询

     for(int i=0;i<Table1.getmax();i++)
     {
         QListWidgetItem *item=new QListWidgetItem(Table1.table[i].getname());
          ui->listWidget->addItem(item);
     }
     j=0;
     while(j<Table1.getmax())//按住址查询
     {
          QListWidgetItem* item = ui->listWidget->takeItem(0);
          QString name=item->text();
          person p;
          for(int i=0;i<Table1.getmax();i++)
          {
              if(Table1.table[i].getname()==name)
              {
                   p=Table1.table[i];
              }
          }
          QString a=p.getadd();
         if(a.indexOf(s)>=0)//如果包含用户输入的字符串，则代表找到了
         {
             item->setText(p.getname()+"("+p.getadd()+")");
              ui->listWidget->addItem(item);
              tag=true;
         }
         else
         {

         }
         j++;
     }
      if(tag)return;//如果找到了，不再继续查询
}

void Widget::new_build()//添加对话框
{
    class new_build*a=new class new_build(this);
    a->show();
}

void Widget::Addperson(QString Name,QString Telephone,QString Address)
{
    person p(Name,Telephone,Address);
    Table1.new_build(p);
    QListWidgetItem *item=new QListWidgetItem(p.getname());
     ui->listWidget->addItem(item);
}

void Widget::Del()
{
     QListWidgetItem *item=ui->listWidget->currentItem();
     QString name=item->text();
     int j;
     for(int i=0;i<Table1.getmax();i++)
     {
         if(Table1.table[i].getname()==name)
         {
             j=i;
         }
     }
     Table1.Del(j);
     ui->listWidget->removeItemWidget(item);
     delete item;
}

void Widget::edit_mess(QString Name,QString Telephone,QString Address)
{
    person p;
    p.setname(Name);
    p.settel(Telephone);
    p.setadd(Address);
     QListWidgetItem *item=ui->listWidget->currentItem();
     QString name=item->text();
    for(int i=0;i<Table1.getmax();i++)
    {
        if(Table1.table[i].getname()==name)
        {
            Table1.table[i]=p;
        }
    }
    ui->listWidget->removeItemWidget(item);
    item->setText(Name);
}

void Widget::changedialog()
{
    QListWidgetItem *item=ui->listWidget->currentItem();
    QString name=item->text();
    person p;
    for(int i=0;i<Table1.getmax();i++)
    {
        if( name.indexOf(Table1.table[i].getname())>=0)
        {
            p=Table1.table[i];
        }
    }

    class changedialog*a=new class changedialog(this,p.getname(),p.gettel(),p.getadd());
    a->setAttribute(Qt::WA_DeleteOnClose);
    a->show();
   }




