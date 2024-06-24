#ifndef PERSON_H
#define PERSON_H

#include "QString"


class person
{
public:
    person();
    person(QString Name,QString Telephone,QString Address);
    QString getname();
    QString gettel();
    QString getadd();

    void setname(QString Name);
    void settel(QString Telephone);
    void setadd(QString Address);

private:
    QString name;
    QString tel;
    QString add;

};

#endif // PERSON_H
