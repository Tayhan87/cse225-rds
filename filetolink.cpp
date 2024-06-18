#ifndef FILETOLINK_H
#define FILETOLINK_H


#include<iostream>
#include<fstream>
#include"coursename.cpp"
#include"coursedetail.cpp"

class filetolink
{

public:


    coursename<string,string,string> nametolist()
    {

        ifstream read("E:\\CPP\\Project 2.0\\RDS\\coursename.txt");
        if(!read.is_open())
        {
            cout<<"File could not find."<<endl;
            return coursename<string,string,string>();
        }
        coursename<string,string,string> c;
        string s,id="",name="",code="";
        int k=0;
        while(getline(read,s))
        {
            for(int i=0; i<s.length(); i++)
            {
                if(s[i]==',')
                {
                    k++;
                }
                else if(k==0)
                    id+=s[i];
                else if(k==1)
                    name+=s[i];
                else if(k==2)
                    code+=s[i];
            }
            c.insertcourse(id,name,code);
            id="";
            name="";
            code="";
            k=0;
        }
        read.close();
        return c;
    }

    coursedetail<string,string,string,string,string,string,string> detailtolist()
    {

        ifstream read2("E:\\CPP\\Project 2.0\\RDS\\coursedetail.txt");
        if(!read2.is_open())
        {
            cout<<"File could not find."<<endl;
            return   coursedetail<string,string,string,string,string,string,string>();
        }

        coursedetail<string,string,string,string,string,string,string> c;
        string str,section="",days="",timing="",room="",faculty="",credit="",id="";
        int k=0;
        while(getline(read2,str))
        {
            for(int i=0; i<str.length(); i++)
            {
                if(str[i]==',')
                    k++;

                else if(k==0)
                    id+=str[i];

                else if(k==1)
                    section+=str[i];

                else if(k==2)
                    days+=str[i];

                else if(k==3)
                    timing+=str[i];

                else if(k==4)
                    room+=str[i];

                else if(k==5)
                    faculty+=str[i];

                else if(k==6)
                    credit+=str[i];
            }

            c.insertcourse(id,section,days,timing,room,faculty,credit);
            id="";
            section="";
            days="";
            timing="";
            room="";
            faculty="";
            credit="";
            k=0;
        }
        read2.close();
        return c;
    }

    void printname(auto c1)
    {
        string a,b,c;
        for(int i=0; i<c1.getlength(); i++)
        {
            c1.getcourse(a,b,c);
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
    }
    void printdetail(auto c1)
    {
        string a,b,c,d,e,f,g;
        for(int i=0; i<c1.getlength(); i++)
        {
            c1.getcourse(a,b,c,d,e,f,g);
            cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<endl;
        }
    }

};
#endif
