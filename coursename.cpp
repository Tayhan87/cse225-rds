#ifndef COURSENAME_H
#define COURSENAME_H

#include<iostream>
using namespace std;


class coursename
{

public:
    struct node
    {
        string id;
        string department;
        string name;
        string code;
        node* next;
    };

private:
    node* courselist;
    node* currentlocation;
    int length;

public:
    coursename()
    {
        courselist=NULL;
        currentlocation=NULL;
        length=0;
    }

    void insertcourse(string a, string b, string c, string d)
    {
        node* temp=new node;
        temp->id=a;
        temp->department=b;
        temp->name=c;
        temp->code=d;
        temp->next=courselist;
        courselist=temp;
        length++;
    }


    void deletecourse(string a)
    {
        node* temp;
        temp=courselist;
        if(temp->id==a)
        {
            courselist=courselist->next;
            delete temp;
        }
        else
        {
            while(temp!=NULL && temp->next!=NULL)
            {
                if(temp->next->id==a)
                {
                    currentlocation=temp->next;
                    temp->next=temp->next->next;
                    delete currentlocation;
                    length--;

                }
                temp=temp->next;
            }
        }

    }

    void getcourse(string &a,string &b,string &c,string &d)
    {

        if(currentlocation==NULL)
            currentlocation=courselist;
        else
            currentlocation=currentlocation->next;
        if(currentlocation!=nullptr)
        {
            a=currentlocation->id;
            b=currentlocation->department;
            c=currentlocation->name;
            d=currentlocation->code;
        }
    }

    int getlength()
    {
        return length;
    }

    node* getCourselist() const
    {
        return courselist;
    }

    void reset(){
    currentlocation=nullptr;
    }

};
#endif
