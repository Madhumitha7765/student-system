#include "Teacher.h"
#include<fstream>
#include<iomanip>
#include<string>

bool Teacher::Login() //shows menu only when username and password is correct
{
    system("cls");
    string username,password;
    cout<<"\n\t\t\t\t\t TEACHER LOGIN PAGE\n"<<endl;
    cout<<"\n\t\t\t\t\tUSERNAME : ";
    cin>>username;
    cout<<"\n\t\t\t\t\t PASSWORD : ";
    cin>>password;
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
        else if(i==length-1)
        {
            cout<<"\n\t\t\t\t\tIncorrect username!"<<endl;
            return 0;
        }
    }
}

void Teacher::addAssignment()//adds new record to Assignment.txt
{
    string id;
    int cls,noq;
    string noa,totmarks;
    cout<<"\n\t\t\t\t\tEnter assignment ID:";
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
    for(i=0;i<length;i++)
    {
        if (assignments[i][0]==id)// checks if record exists with same assignment id
        {
            cout<<"\n\t\t\t\t\tAssignment ID already exists!"<<endl;
            break;
        }
        else
        {
            cout<<"\n\t\t\t\t\tEnter class :";
            cin>>cls;
            cout<<"\n\t\t\t\t\tEnter name of assignment :";
            cin>>noa;
            cout<<"\n\t\t\t\t\tEnter number of questions (max 5 questions): ";
            cin>>noq;
            if (noq>5)
            {
                cout<<"\n\t\t\t\t\tthe number of questions should be less than 5";
                cout<<"\n\t\t\t\t\tEnter number of questions (max 5 questions): ";
                cin>>noq;
            }
            cout<<"\n\t\t\t\t\tEnter total number of marks : ";
            cin>>totmarks;
            getchar();
            f.open("Assignment.txt",ios::app);
            f<<id<<'\t'<<cls<<'\t'<<noa<<'\t'<<noq<<'\t'<<totmarks;
            string q;
            for(i=noq;i>0;i--)
            {
                cout<<"\n\t\t\t\t\tEnter question : ";
                getline(cin,q);
                f<<'\t'<<q;
            }
            if (noq<5)
            {
                for(i=noq;i<5;i++)
                {
                    f<<'\t'<<" ";
                }
            }
            f<<endl;
            cout<<"\n\t\t\t\t\tAssignment added succesfully"<<endl;
            f.close();
                }
            }

}

void Teacher::evaluateAssignment()//evaluates student's submission
{
    string aid;
    cout<<"\n\t\t\t\t\tEnter assignment ID : ";
    cin>>aid;
    fstream f;
    fstream fm;
    fm.open("Assignment.txt",ios::in);
    int i=0;
    string line;
    int lengtha=0;
    while(getline(fm,line))
    {
        lengtha++;
    }
    string questions[lengtha][10];
    fm.close();
    int j=0;
    fm.open("Assignment.txt", ios::in);
    while(getline(fm,line))
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
    fm.close();
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
    int length=0;
    while(getline(f,line))
    {
        length++;
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
    cout<<"\n\t\t\t\t\tID's of students submitted"<<endl;
    for (i=0;i<length;i++)
    {
        cout<<assignments[i][1]<<endl;
    }
    string sid;
    cout<<"\n\t\t\t\t\tEnter Student ID to evaluate : ";
    cin>>sid;
    cout<<"\n\t\t\t\t\tNumber of questions : "<<noq<<endl;
    f.open("Marks.txt",ios::app);
    f<<aid<<'\t'<<sid;
    int studid_not_found=0;
    for(i=0;i<lengtha;i++)
    {
        if (assignments[i][1]== sid)
        {
            cout<<"\n\t\t\t\t\tTotal marks for this assignment:"<<question[1]<<endl;
            int tot_marks=0;
            string m;
            int mark;
            for(j=2;j<noq+2;j++)
            {
                cout<<"\n\t\t\t\t\tQuestion : "<<question[j]<<endl;
                cout<<"\n\t\t\t\t\tStudent Answer : "<<assignments[i][j]<<endl;
                cout<<"\n\t\t\t\t\tEnter marks : ";
                cin>>m;
                f<<'\t'<<m;
                mark=stoi(m);
                tot_marks=tot_marks+mark;
            }
            for(int x=noq;x<5;x++)
            {
                f<<'\t'<<" ";
            }
            f<<'\t'<<tot_marks<<'\n';
            cout<<"\n\t\t\t\t\tTOTAL MARKS : "<<tot_marks<<endl;
            studid_not_found=1;
        }
        else if(i==lengtha-1 && studid_not_found==0)
        {
            cout<<"\n\t\t\t\t\tStudent Submission not found!"<<endl;
        }
    }
}


