#ifndef PASSWORDFILE_H
#define PASSWORDFILE_H


#include<iostream>
#include<fstream>
#include"passwordlist.cpp"

class passtolink
{
public:

    passlist<string,string> faculty_password_to_list()
    {

        ifstream read("E:\\CPP\\Project 2.0\\cse225-rds\\facultypassword.txt");

        if(!read.is_open())
        {
            cout<<"File could not find."<<endl;
            return passlist<string,string>();
        }

        passlist<string,string>p;
        string id="",pass="",s;

        int k=0;
        while(getline(read,s))
        {

            for(int i=0; i<s.length(); i++)
            {

                if(s[i]==',')
                    k++;

                else if(k==0)
                    id+=s[i];

                else if(k==1)
                    pass+=s[i];
            }
            p.insertidpass(id,pass);
            id="";
            pass="";
            k=0;
        }
        read.close();
        return p;
    }

    passlist<string,string> student_password_to_list()
    {

        ifstream read("E:\\CPP\\Project 2.0\\cse225-rds\\studentpassword.txt");

        if(!read.is_open())
        {
            cout<<"File could not find."<<endl;
            return passlist<string,string>();
        }

        passlist<string,string>p;
        string id="",pass="",s;

        int k=0;
        while(getline(read,s))
        {

            for(int i=0; i<s.length(); i++)
            {

                if(s[i]==',')
                    k++;

                else if(k==0)
                    id+=s[i];

                else if(k==1)
                    pass+=s[i];
            }
            p.insertidpass(id,pass);
            id="";
            pass="";
            k=0;
        }
        read.close();
        return p;
    }

};
#endif
