#include "Student.h"
#include<fstream>
#include<string>

bool Student::Login()//shows menu only when username and password is correct
{
    system("cls");
    string username,password;
    cout<<"\n\t\t\t\t\tSTUDENT LOGIN PAGE\n"<<endl;
    cout<<"\n\t\t\t\t\tUSERNAME : ";
    cin>>username;
    cout<<"\n\t\t\t\t\t PASSWORD : ";
    cin>>password;
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
    for (i=0;i<length;i++)
    {
        if (details[i][0]==username)
        {
            if (details[i][2]==password)
            {
                cout<<"\n\t\t\t\t\tLogin Successfull!"<<endl;
                return 1;
            }
            else
            {
                cout<<"\n\t\t\t\t\tIncorrect Password!"<<endl;
                return 0;
            }
        }
        else if(i=length-1)
        {
            cout<<"\n\t\t\t\t\tIncorrect username!"<<endl;
            return 0;
        }
    }
}

void Student::viewAssignment()// displays record of Assignment.txt
{
    string id;
    cout<<"\n\t\t\t\t\tEnter Assignment ID : ";
    cin>>id;
    fstream f;
    int i=0;
    f.open("Assignment.txt", ios::in);
    string line;
    int length=0;
    while(getline(f,line))
    {
        length++;
    }
    string assignments[length][10];
    int j=0;
    f.close();
    f.open("Assignment.txt", ios::in);
    while(getline(f,line))
    {
        string word = "";
        for (auto x : line)
        {
            if (x == '\t'|| x=='\n')
            {
                assignments[j][i]=word;
                i=i+1;
                word = "";
            }
            else {
                word = word + x;
            }
        }
        assignments[j][i]=word;
        i=i+1;
    }
    f.close();
    int assignment_found=0;
    for (i=0;i<length;i++)
    {
        if (assignments[i][0] == id)
        {
            cout<<"\n\t\t\t\t\tName of exam : "<<assignments[i][2]<<endl;
            cout<<"\n\t\t\t\t\tNumber of questions : "<<assignments[i][3]<<endl;
            cout<<"\n\t\t\t\t\tTotal marks : "<<assignments[i][4]<<endl;
            cout<<assignments[i][5]<<endl;
            cout<<assignments[i][6]<<endl;
            cout<<assignments[i][7]<<endl;
            cout<<assignments[i][8]<<endl;
            cout<<assignments[i][9]<<endl;
            assignment_found=1;
        }
    }
    if (assignment_found==0)
    {
        cout<<"\n\t\t\t\t\tAssignment not found"<<endl;
        cout<<"\n\t\t\t\t\tcontact faculty"<<endl;
    }
}

void Student :: submitAssignment()// adds records to Submitassignment.txt for Teacher to evaluate
{
    string aid,sid;
    cout<<"\n\t\t\t\t\tEnter Assignment ID : ";
    cin>>aid;
    cout<<"\n\t\t\t\t\tEnter Student ID : ";
    cin>>sid;
    fstream f;
    int i=0;
    f.open("Assignment.txt", ios::in);
    string line;
    int length=0;
    while(getline(f,line))
    {
        length++;
    }
    string assignments[length][10];
    int j=0;
    f.close();
    f.open("Assignment.txt", ios::in);
    while(getline(f,line))
    {
        string word = "";
        for (auto x : line)
        {
            if (x == '\t'|| x=='\n')
            {
                assignments[j][i]=word;
                i=i+1;
                word = "";
            }
            else {
                word = word + x;
            }
        }
        assignments[j][i]=word;
        i=i+1;
    }
    f.close();
    int assignment_found=0;
    for (i=0;i<length;i++)
    {
        if (assignments[i][0] == aid)
        {
            cout<<"\n\t\t\t\t\tName of exam : "<<assignments[i][2]<<endl;
            cout<<"\n\t\t\t\t\tNumber of questions : "<<assignments[i][3]<<endl;
            cout<<"\n\t\t\t\t\tTotal marks : "<<assignments[i][4]<<endl;
            cout<<assignments[i][5]<<endl;
            cout<<assignments[i][6]<<endl;
            cout<<assignments[i][7]<<endl;
            cout<<assignments[i][8]<<endl;
            cout<<assignments[i][9]<<endl;
            assignment_found=1;
            f.open("SubmitAssignment.txt",ios::out);
            int noq=stoi(assignments[i][3]);
            string q;
            f<<assignments[i][0]<<'\t'<<sid;
            getchar();
            for (i=0;i<noq;i++)
            {
                cout<<"\n\t\t\t\t\tEnter answer for question "<<i+1<<":";
                getline(cin,q);
                f<<'\t'<<q;
            }
            for (i=noq;i<5;i++)
            {
                f<<'\t'<<" ";
            }
        }
    }
    if (assignment_found==0)
    {
        cout<<"\n\t\t\t\t\tAssignment not found"<<endl;
        cout<<"\n\t\t\t\t\tcontact faculty"<<endl;
    }

}
void Student::viewMarks()//displays evaluated marks
{
    string aid,sid;
    cout<<"\n\t\t\t\t\tEnter assignment ID : ";
    cin>>aid;
    cout<<"\n\t\t\t\t\tEnter student ID : ";
    cin>>sid;
    fstream f;
    f.open("Marks.txt",ios::in);
    string line;
    int length=0;
    while(getline(f,line))
    {
        length++;
    }
    string marks[length][8];
    int j=0;
    int i=0;
    f.close();
    f.open("Marks.txt", ios::in);
    while(getline(f,line))
    {
        string word = "";
        for (auto x : line)
        {
            if (x == '\t'|| x=='\n')
            {
                marks[j][i]=word;
                i=i+1;
                word = "";
            }
            else {
                word = word + x;
            }
        }
        marks[j][i]=word;
        i=i+1;
    }
    f.close();
    f.open("Assignment.txt",ios::in);
    i=0;
    int lengtha=0;
    while(getline(f,line))
    {
        lengtha++;
    }
    string questions[lengtha][10];
    f.close();
    j=0;
    f.open("Assignment.txt", ios::in);
    while(getline(f,line))
    {
        string word = "";
        for (auto x : line)
        {
            if (x == '\t'|| x=='\n')
            {
                questions[j][i]=word;
                i=i+1;
                word = "";
            }
            else {
                word = word + x;
            }
        }
        questions[j][i]=word;
        i=i+1;
    }
    f.close();
    string question[7];
    int noq;
    for (i=0;i<lengtha;i++)
    {
        if (questions[i][0]==aid)
        {
            question[0]="";
            question[1]= questions[i][4];       //total number of marks
            noq=stoi(questions[i][3]);          //no. of questions
            question[2]=questions[i][5];
            question[3]=questions[i][6];
            question[4]=questions[i][7];
            question[5]=questions[i][8];
            question[6]=questions[i][9];
        }
    }
    f.open("SubmitAssignment.txt",ios::in);
    i=0;
    int lengthsa=0;
    while(getline(f,line))
    {
        lengthsa++;
    }
    string assignments[length][7];
    j=0;
    f.close();
    f.open("SubmitAssignment.txt", ios::in);
    while(getline(f,line))
    {
        string word = "";
        for (auto x : line)
        {
            if (x == '\t'|| x=='\n')
            {
                assignments[j][i]=word;
                i=i+1;
                word = "";
            }
            else {
                word = word + x;
            }
        }
        assignments[j][i]=word;
        i=i+1;
    }
    f.close();
    int studans_not_found=0;
    string answer[7];
    answer[0]=aid;
    answer[1]=sid;
    for (i=0;i<lengthsa;i++)
    {
        if (assignments[i][0]==aid)
        {
            if (assignments[i][1]==sid)
            {
                answer[2]=assignments[i][2];
                answer[3]=assignments[i][3];
                answer[4]=assignments[i][4];
                answer[5]=assignments[i][5];
                answer[6]=assignments[i][6];
                answer[7]=assignments[i][7];
            }
        }
    }
    for(i=0;i<length;i++)
    {
        if (marks[i][0]== aid)
        {
            if (marks[i][1]==sid)
            {
                cout<<"\n\t\t\t\t\tTotal marks for this assignment:"<<question[1]<<endl;
                for(j=2;j<noq+2;j++)
                {
                    cout<<"Question : "<<question[j]<<endl;
                    cout<<"Your Answer : "<<answer[j]<<endl;
                    cout<<"Marks : "<<marks[i][j]<<endl;
                }
                studans_not_found=1;
                cout<<"Your marks : "<<marks[i][7]<<endl;
            }
        }
        else if(i==lengtha-1 && studans_not_found==0)
        {
            cout<<"\n\t\t\t\t\tStudent mark not found!"<<endl;
        }
    }
}
