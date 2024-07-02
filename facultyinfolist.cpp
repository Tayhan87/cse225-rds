#include "facultyinfolist.h"
#include <iostream>

using namespace std;

faculty_info_list::faculty_info_list() : facultylist(nullptr), currentlocation(nullptr), length(0) {}

void faculty_info_list::insertinfo(const string& a1, const string& a2, const string& a3, const string& a4, const string& a5, const string& a6, const string& a7, const string& a8, const string& a9)
{
    node* temp = new node{a1, a2, a3, a4, a5, a6, a7, a8, a9, facultylist};
    facultylist = temp;
    length++;
}

void faculty_info_list::deleteinfo(const string& a)
{
    node* temp = facultylist;
    node* prev = nullptr;

    while (temp != nullptr)
    {
        if (temp->initial == a)
        {
            if (prev == nullptr)
            {
                facultylist = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            length--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

int faculty_info_list::getlength() const
{
    return length;
}

void faculty_info_list::getfacultyinfo(string& a1, string& a2, string& a3, string& a4, string& a5, string& a6, string& a7, string& a8, string& a9)
{
    if (currentlocation == nullptr)
        currentlocation = facultylist;
    else
        currentlocation = currentlocation->next;

    if (currentlocation != nullptr)
    {
        a1 = currentlocation->initial;
        a2 = currentlocation->name;
        a3 = currentlocation->qualification;
        a4 = currentlocation->dob;
        a5 = currentlocation->phone;
        a6 = currentlocation->department;
        a7 = currentlocation->pass;
        a8 = currentlocation->prof_email;
        a9 = currentlocation->per_email;
    }
}

void faculty_info_list::reset()
{
    currentlocation = nullptr;
}

bool faculty_info_list::login(string id,string password)
{
    node* temp=facultylist;
    while(temp!=nullptr)
    {
        if(temp->initial==id)
        {
            if(temp->pass==password)
            {
                return true;
            }

        }
        temp=temp->next;
    }
    return false;
}

faculty_info_list::node* faculty_info_list::getfacultylisthead() const
{
    return facultylist;
}

