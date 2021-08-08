#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include "Teacher.h"
#include "Student.h"
#include "Subject.h"
#include "Class.h"
using namespace std;


class Admin : public Teacher,public Student,public Subject,public Class
{
    public:
    int id;
    string name;
    string password;
    Admin(int a=0,string b="user_not_found",string c="0000")
    {
        id=a;
        name=b;
        password=c;
    }
    bool login();
    void AddNewTeacher();
    void ModifyTeacher();
    void AddNewStudent();
    void ModifyStudent();
    void DisplayTeacher();
    void DisplayStudent();

};

#endif // ADMIN_H
