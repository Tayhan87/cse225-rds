#ifndef PASSWORDLIST_H
#define PASSWORDLIST_H

#include<iostream>

using namespace std;

template<class t1,class t2>

class passlist
{

public:
    struct node{

        t1 id;
        t2 pass;
        node* next;
    };

private:
    node* password_list;
    node* currentlocation;
    int length;

public:
    passlist(){
        password_list=NULL;
        currentlocation=NULL;
        length=0;
    }

    void insertidpass(t1 a, t2 b)
    {
        node* temp=new node;
        temp->id=a;
        temp->pass=b;

        temp->next=password_list;
        password_list=temp;
        length++;
    }


    void deleteidpass(t1 a)
    {
        node* temp;
        temp=password_list;
        if(temp->id==a)
        {
            password_list=password_list->next;
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

    void getidpass(t1 &a,t2 &b)
    {

        if(currentlocation==NULL)
            currentlocation=password_list;
        else
            currentlocation=currentlocation->next;
        if(currentlocation!=nullptr)
        {
            a=currentlocation->id;
            b=currentlocation->pass;

        }
    }

    bool retrivepass(string i, string p){

          node* temp=password_list;
          while(temp!=NULL){
            if(temp->id==i)
            {
                if(temp->pass==p)
                    return true;
                else
                    return false;
            }
            temp=temp->next;
          }
          return false;
    }

    int getlength()
    {
        return length;
    }
    node* getlist() const
    {
        return password_list;
    }

};
#endif

