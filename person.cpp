#include "person.h"

person::person()
{

}

person::person(QString Name,QString Telephone,QString Address)
{
    name=Name;
    tel=Telephone;
    add=Address;
}
QString person::getname()
{
    return name;
}
 QString person::gettel()
{
    return tel;
}
QString person::getadd()
{
    return add;
}
void person::setname(QString Name)
{
    name=Name;
}
void person::settel(QString Telephone)
{
    tel=Telephone;
}
void person::setadd(QString Address)
{
    add=Address;
}
