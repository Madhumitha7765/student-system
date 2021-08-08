#include "Admin.h"
#include "Teacher.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;


bool Admin::login()//shows menu only when username and password is correct
{
    system("cls");
    string username,password;
    cout<<"\n\t\t\t\t\tADMIN LOGIN PAGE"<<endl;
    cout<<"\n\t\t\t\t\tUSERNAME : ";
    cin>>username;
    cout<<"\n\t\t\t\t\t PASSWORD : ";
    cin>>password;
    if (username == "admin")
    {
        if (password=="12345")//defined
        {
            cout<<"\n\t\t\t\t\tLogin Successfull!"<<endl;
            return 0;
        }
        else{
            cout<<"\n\t\t\t\t\tLogin unsuccessfull"<<endl;
            return 1;
        }
    }
    else
    {
        cout<<"\n\t\t\t\t\tLogin Unsuccessfull"<<endl;
        cout<<"\n\t\t\t\t\tAdmin denied"<<endl;
        return 1;
    }
}

void Admin::AddNewTeacher() //adds new record to Teacher.txt
{

        fstream f;
        string id,name,pno,address;
        cout<<"\n\t\t\tEnter Teacher's id : ";
        cin>>id;
        int i=0;
        f.open("Teacher.txt", ios::in);
        string line;
        int length=0;
        while(getline(f,line))
        {
            length++;
        }
        string details[length][4];
        int j=0;
        f.close();
        f.open("Teacher.txt", ios::in);
        while(getline(f,line))
        {
            string word = "";
            for (auto x : line)
            {
                if (x == '\t'|| x=='\n')
                {
                    details[j][i]=word;
                    i=i+1;
                    word = "";
                }
                else {
                    word = word + x;
                }
            }
            details[j][i]=word;
            i=i+1;
        }
        for(i=0;i<length;i++)
        {
            if (details[i][0]==id)
            {
                cout<<"\n\t\t\tTeacher ID already exists!"<<endl;
                break;
            }
            else
            {
                cout<<"\n\t\t\tEnter Teacher's name : ";
                cin>>name;
                cout<<"\n\t\t\tEnter Teacher's Phone Number : ";
                cin>>pno;
                cout<<"\n\t\t\tEnter Teacher's Address : ";
                cin>>address;
                f.open("Teacher.txt", ios::app);
                f<<id<<"\t"<<name<<"\t"<<pno<<"\t"<<address<<endl;
                cout<<"\n\t\t\tTeacher Successfully Added!"<<'\n'<<endl;
                f.close();//file updated
            }
        }
}

void Admin::DisplayTeacher()//displays all records from Teacher.txt
{
    string info[4] = {"ID","NAME","PHONE NUMBER","ADDRESS"};
    fstream f;
    int i=0;
    f.open("Teacher.txt", ios::in);
    string line;
    int length=0;
    while(getline(f,line))
    {
        length++;
    }
    string details[length][4];
    int j=0;
    f.close();
    f.open("Teacher.txt", ios::in);
    while(getline(f,line))
    {
        string word = "";
        for (auto x : line)
        {
            if (x == '\t'|| x=='\n')
            {
                details[j][i]=word;
                i=i+1;
                word = "";
            }
            else {
                word = word + x;
            }
        }
        details[j][i]=word;
        i=i+1;
    }
    for (j=0;j<length;j++)
    {
        cout<<"\nDisplaying info of Teacher number "<<j+1<<endl;
        for (i=0;i<4;i++)
        {
            cout<<info[i]<<" : "<<details[j][i]<<endl;
        }
        cout<<endl;
    }
}

void Admin::ModifyTeacher()//modifies record of Teacher.txt
{
    string id;
    fstream f;
    fstream fm;
    cout<<"\n\t\t\tEnter the id of the teacher that you want to modify : ";
    cin>>id;
    int i=0;
    f.open("Teacher.txt", ios::in);
    string line;
    int length=0;
    while(getline(f,line))
    {
        length++;
    }
    string details[length][4];
    int j=0;
    f.close();
    f.open("Teacher.txt", ios::in);
    while(getline(f,line))
    {
        string word = "";
        for (auto x : line)
        {
            if (x == '\t'|| x=='\n')
            {
                details[j][i]=word;
                i=i+1;
                word = "";
            }
            else {
                word = word + x;
            }
        }
        details[j][i]=word;
        i=i+1;
    }
    int teacher_not_found=0;
    for (i=0;i<length;i++)
    {
        if (details[i][0] == id)//new data
        {
            cout<<"\n\t\t\tEnter Name         : ";
            cin>>details[i][1];
            cout<<"\n\t\t\tEnter Phone Number : ";
            cin>>details[i][2];
            cout<<"\n\t\t\tEnter Address      : ";
            cin>>details[i][3];
            cout<<"\n\t\t\tTeacher Successfully Modified!"<<'\n'<<endl;
            teacher_not_found =1;
        }
        else if(i==length-1 && teacher_not_found ==0)
        {
            cout<<"\n\t\t\tTeacher Not found "<<endl;
        }
    }
    fm.open("Modify.txt",  ios::app);
    for (i=0;i<length;i++)
    {
        fm<<details[i][0]<<'\t'<<details[i][1]<<'\t'<<details[i][2]<<'\t'<<details[i][3]<<'\n';
    }
    f.close();
    fm.close();
    remove("Teacher.txt");
    char old_name[] = "Modify.txt";
    char new_name[] = "Teacher.txt";//updated file
    rename(old_name, new_name);
}


void Admin::AddNewStudent()// adds record to Student.txt
{
    fstream f;
        string id,name,pno,address;
        cout<<"\n\t\t\tEnter Student's id : ";
        cin>>id;
        int i=0;
        f.open("Student.txt", ios::in);
        string line;
        int length=0;
        while(getline(f,line))
        {
            length++;
        }
        string details[length][4];
        int j=0;
        f.close();
        f.open("Student.txt", ios::in);
        while(getline(f,line))
        {
            string word = "";
            for (auto x : line)
            {
                if (x == '\t'|| x=='\n')
                {
                    details[j][i]=word;
                    i=i+1;
                    word = "";
                }
                else {
                    word = word + x;
                }
            }
            details[j][i]=word;
            i=i+1;
        }
        for(i=0;i<length;i++)
        {
            if (details[i][0]==id)//checks if stud record exists with same id
            {
                cout<<"\n\t\t\tStudent ID already exists!"<<endl;
                break;
            }
            else
            {
                Student s;
                fstream f;
                cout<<"\n\t\t\tEnter Student's id : ";
                cin>>s.id;
                cout<<"\n\t\t\tEnter Student's name : ";
                cin>>s.name;
                cout<<"\n\t\t\tEnter Student's Phone Number : ";
                cin>>s.pno;
                cout<<"\n\t\t\tEnter Student's Address : ";
                cin>>s.address;
                f.open("Student.txt",ios::out|ios::app);
                f<<s.id<<"\t"<<s.name<<"\t"<<s.pno<<"\t"<<s.address<<'\n';
                f.close();//file updated
            }
        }

}

void Admin::DisplayStudent()// displays all records of Student.txt
{
    string info[4] = {"ID","NAME","PHONE NUMBER","ADDRESS"};
    fstream f;
    int i=0;
    f.open("Student.txt", ios::in);
    string line;
    int length=0;
    while(getline(f,line))
    {
        length++;
    }
    string details[length][4];
    int j=0;
    f.close();
    f.open("Student.txt", ios::in);
    while(getline(f,line))
    {
        string word = "";
        for (auto x : line)
        {
            if (x == '\t'|| x=='\n')
            {
                details[j][i]=word;
                i=i+1;
                word = "";
            }
            else {
                word = word + x;
            }
        }
        details[j][i]=word;
        i=i+1;
    }
    for (j=0;j<length;j++)
    {
        cout<<"\nDisplaying info of Student number "<<j+1<<endl;
        for (i=0;i<4;i++)
        {
            cout<<info[i]<<" : "<<details[j][i]<<endl;
        }
        cout<<endl;
    }
}

void Admin::ModifyStudent()//modifies record of Student.txt
{
    string id;
    fstream f;
    fstream fm;
    cout<<"\n\t\t\tEnter the id of the student that you want to modify : ";
    cin>>id;
    int i=0;
    f.open("Student.txt", ios::in);
    string line;
    int length=0;
    while(getline(f,line))
    {
        length++;
    }
    string details[length][4];
    int j=0;
    f.close();
    f.open("Student.txt", ios::in);
    while(getline(f,line))
    {
        string word = "";
        for (auto x : line)
        {
            if (x == '\t'|| x=='\n')
            {
                details[j][i]=word;
                i=i+1;
                word = "";
            }
            else {
                word = word + x;
            }
        }
        details[j][i]=word;
        i=i+1;
    }
    int student_not_found=0;
    for (i=0;i<length;i++)
    {
        if (details[i][0] == id)
        {
            cout<<"\n\t\t\tEnter Name         : ";
            cin>>details[i][1];
            cout<<"\n\t\t\tEnter Phone Number : ";
            cin>>details[i][2];
            cout<<"\n\t\t\tEnter Address      : ";
            cin>>details[i][3];
            cout<<"\n\t\t\tStudent Successfully Modified!"<<'\n'<<endl;
            student_not_found=1;//new data
        }
        else if(i==length-1 && student_not_found == 0)
        {
            cout<<"\n\t\t\tStudent not found!"<<endl;
        }
    }
    fm.open("Modify.txt",  ios::app);
    for (i=0;i<length;i++)
    {
        fm<<details[i][0]<<'\t'<<details[i][1]<<'\t'<<details[i][2]<<'\t'<<details[i][3]<<'\n';
    }
    f.close();
    fm.close();
    remove("Student.txt");
    char old_name[] = "Modify.txt";
    char new_name[] = "Student.txt";
    rename(old_name, new_name);//updated file

}


