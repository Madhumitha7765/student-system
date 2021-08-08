#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
using namespace std;

class Student
{
    public:
        int id,pno;
        string name,address;
        Student(int i=0,string n="no_name",int p=0,string add="no_add")
        {
            id=i;
            name=n;
            pno=p;
            address=add;
        }
        bool Login();
        void viewAssignment();
        void submitAssignment();
        void viewMarks();

    protected:

    private:
};

#endif // STUDENT_H
