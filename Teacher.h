#include<iostream>
using namespace std;
#ifndef TEACHER_H
#define TEACHER_H


class Teacher
{
    public:
        int id,pno;
        string name,address;
        Teacher(int i=0,string n="no_name",int p=0,string add="no_add")
        {
            id=i;
            name=n;
            pno=p;
            address=add;
        }
        bool Login();
        void addAssignment();
        void evaluateAssignment();

    protected:

    private:
};

#endif // TEACHER_H
