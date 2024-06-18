#ifndef COURSENAME_H
#define COURSENAME_H

#include<iostream>
using namespace std;

template<class t1,class t2, class t3>

class coursename
{

public:
    struct node
    {
        t1 id;
        t2 name;
        t3 code;
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

    void insertcourse(t1 a, t2 b, t3 c)
    {
        node* temp=new node;
        temp->id=a;
        temp->name=b;
        temp->code=c;
        temp->next=courselist;
        courselist=temp;
        length++;
    }


    void deletecourse(t1 a)
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

    void getcourse(t1 &a,t2 &b,t3 &c)
    {

        if(currentlocation==NULL)
            currentlocation=courselist;
        else
            currentlocation=currentlocation->next;
        if(currentlocation!=nullptr)
        {
            a=currentlocation->id;
            b=currentlocation->name;
            c=currentlocation->code;
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

};
#endif
