#include "persontable.h"

persontable::persontable()
{
   maxsize=1;
    table=new person[maxsize];
    current=0;
  }

persontable::~persontable()
{
    delete []table;
}

void persontable::new_build(person p)
{
    if(current==maxsize)
    {
        person*table1=new person[maxsize+1];
        for(int i=0;i<maxsize;i++)
        {
           table1[i]=table[i];
        }
        table=table1;
        maxsize=maxsize+1;
     }
     table[current]=p;
     current++;
}
void persontable::Del(int j)
{
    for(int i=j;i<maxsize-1;i++)
    {
        table[i]=table[i+1];
    }
        current--;
        maxsize--;
}

int persontable::getmax()
{
     return maxsize;
}
