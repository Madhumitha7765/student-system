#include <iostream>
#include "Admin.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;


int main()
{
    char block=178;
    int c=1;
    while(c!=0) //menu
    {
        cout<<"\n\t\t\t\t\t\t\t"<< block<< block<<" SCHOOL MANAGEMENT SYSTEM "<<block<<block<<endl;
        cout<<"\n\t\t\t\t\t1.Admin"<<endl;
        cout<<"\n\t\t\t\t\t2.Teacher"<<endl;
        cout<<"\n\t\t\t\t\t3.Student"<<endl;
        cout<<"\n\t\t\t\t\t0.Exit"<<endl;
        cout<<"\n\t\t\t\t\tEnter your choice : ";
        cin>>c;
        switch (c)
        {
        case 1:
            {
                int login;
                Admin a;
                login=a.login();
                if (login == 0)
                    {
                        int ch=1;
                        while(ch!=0)//admin menu
                        {
                            cout<<"\n\t\t\t1.Add New Teacher"<<endl;
                            cout<<"\n\t\t\t2.Modify Teacher"<<endl;
                            cout<<"\n\t\t\t3.Display all Teachers"<<endl;
                            cout<<"\n\t\t\t4.Add New Student"<<endl;
                            cout<<"\n\t\t\t5.Modify Student"<<endl;
                            cout<<"\n\t\t\t6.Display all Students"<<endl;
                            cout<<"\n\t\t\t0.Logout"<<endl;
                            cin>>ch;
                            switch(ch)//admin function call
                            {
                            case 1:
                                {
                                    a.AddNewTeacher();
                                    break;
                                }
                            case 2:
                                {
                                    a.ModifyTeacher();
                                    break;
                                }
                            case 3:
                                {
                                    a.DisplayTeacher();
                                    break;
                                }
                            case 4:
                                {
                                    a.AddNewStudent();
                                    break;
                                }
                            case 5:
                                {
                                    a.ModifyStudent();
                                    break;
                                }
                            case 6:
                                {
                                    a.DisplayStudent();
                                    break;
                                }
                            case 0:
                                {
                                    break;
                                }
                            default:
                                cout<<"\n\t\t\tEnter a valid choice!"<<endl;
                            }
                        }
                    }
                break;
            }
        case 2:
            {
                int login;
                Teacher t;
                login=t.Login();
                if (login==1)
                {
                    int ch=1;
                    while(ch!=0)//teacher menu
                    {
                        cout<<"\n\t\t\t1.Add Assignment"<<endl;
                        cout<<"\n\t\t\t2.Evaluate Assignment"<<endl;
                        cout<<"\n\t\t\t0.Logout"<<endl;
                        cin>>ch;
                        switch(ch)//teacher function call
                        {
                        case 1:
                            {
                                t.addAssignment();
                                break;
                            }
                        case 2:
                            {
                                t.evaluateAssignment();
                                break;
                            }
                        case 0:
                            {
                                break;
                            }
                        }
                    }
                }
                break;
            }
        case 3:
            {
                int login;
                Student s;
                login=s.Login();
                if (login==1)
                {
                    int ch=1;
                    while(ch!=0)//student menu
                    {
                        cout<<"\n\t\t\t\t\t1.View Assignment"<<endl;
                        cout<<"\n\t\t\t\t\t2.Submit Assignment"<<endl;
                        cout<<"\n\t\t\t\t\t3.View Marks"<<endl;
                        cout<<"\n\t\t\t\t\t0.Logout"<<endl;
                        cin>>ch;
                        switch(ch)//student function call
                        {
                        case 1:
                            {
                                s.viewAssignment();
                                break;
                            }
                        case 2:
                            {
                                s.submitAssignment();
                                break;
                            }
                        case 3:
                            {
                                s.viewMarks();
                                break;
                            }
                        case 0:
                            {
                                break;
                            }
                        }
                    }
                }
                break;
            }
        case 0:
            {
                break;
            }
        default:
            cout<<"\n\t\t\t\t\tEnter a valid choice !"<<endl;
        }
    }

    return 0;
}
//end
