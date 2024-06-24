#ifndef PERSONTABLE_H
#define PERSONTABLE_H
#include <person.h>
#include <QTextStream>

class persontable
{
public:
    persontable();
    ~persontable();
    void new_build(person p);
    void Del(int j);
    person*table;
    int getmax();

private:
    int maxsize;
    int current;

};


#endif // PERSONTABLE_H
