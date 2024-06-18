#ifndef COURSEDETAIL_H
#define COURSEDETAIL_H

#include<iostream>
using namespace std;

template<class t1, class t2, class t3, class t4, class t5, class t6, class t7>

class coursedetail
{

public:
    struct node
    {
        t1 id;
        t2 section;
        t3 days;
        t4 timing;
        t5 room;
        t6 faculty;
        t7 credit;
        node* next;
    };

private:
    node* courselist;
    node* currentlocation;
    int length;

public:
    coursedetail()
    {
        courselist=NULL;
        currentlocation=NULL;
        length=0;
    }

    void insertcourse(t1 a, t2 b, t3 c, t4 d, t5 e, t6 f, t7 g)
    {

        node* temp=new node;

        temp->id=a;
        temp->section=b;
        temp->days=c;
        temp->timing=d;
        temp->room=e;
        temp->faculty=f;
        temp->credit=g;

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

                }
                temp=temp->next;
            }
        }

    }

    int getlength()
    {
        return length;
    }

    void getcourse(t1 &a, t2 &b, t3 &c, t4 &d, t5 &e, t6 &f, t7 &g)
    {

        if(currentlocation==NULL)
            currentlocation=courselist;
        else
            currentlocation=currentlocation->next;
        if(currentlocation!=nullptr)
        {
            a=currentlocation->id;
            b=currentlocation->section;
            c=currentlocation->days;
            d=currentlocation->timing;
            e=currentlocation->room;
            f=currentlocation->faculty;
            g=currentlocation->credit;
        }

    }

    node* getCourselist() const
    {
        return courselist;
    }

};
#endif



