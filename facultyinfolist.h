#ifndef FACULTYINFOLIST_H
#define FACULTYINFOLIST_H

#include <string>

using namespace std;

class faculty_info_list
{
public:
    struct node
    {
        string initial;
        string name;
        string qualification;
        string dob;
        string phone;
        string department;
        string pass;
        string prof_email;
        string per_email;
        node* next;
    };

private:
    node* facultylist;
    node* currentlocation;
    int length;

public:
    faculty_info_list();

    void insertinfo(const string& a1, const string& a2, const string& a3, const string& a4, const string& a5, const string& a6, const string& a7, const string& a8, const string& a9);
    void deleteinfo(const string& a);
    int getlength() const;
    void getfacultyinfo(string& a1, string& a2, string& a3, string& a4, string& a5, string& a6, string& a7, string& a8, string& a9);
    void reset();
    bool login(string,string);
    node* getfacultylisthead() const;
};

#endif // FACULTYINFOLIST_H

