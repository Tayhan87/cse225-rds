#include "facultyinfofile.h"
#include <fstream>
#include <iostream>

using namespace std;

faculty_info_list facultyinfofile::infotolist()
{
    ifstream read("E:\\CPP\\Project 2.0\\cse225-rds\\facultyinfo.txt");
    if (!read.is_open())
    {
        cout << "File could not find." << endl;
        return faculty_info_list();
    }

    faculty_info_list fil;
    string s, initial = "", name = "", qualification = "", dob = "", phone = "", department = "", pass = "", prof_email = "", per_email = "";
    int k = 0;

    while (getline(read, s))
    {
        for (char ch : s)
        {
            if (ch == ',')
            {
                k++;
            }
            else if (k == 0)
            {
                initial += ch;
            }
            else if (k == 1)
            {
                name += ch;
            }
            else if (k == 2)
            {
                qualification += ch;
            }
            else if (k == 3)
            {
                dob += ch;
            }
            else if (k == 4)
            {
                phone += ch;
            }
            else if (k == 5)
            {
                department += ch;
            }
            else if (k == 6)
            {
                pass += ch;
            }
            else if (k == 7)
            {
                prof_email += ch;
            }
            else if (k == 8)
            {
                per_email += ch;
            }
        }

        fil.insertinfo(initial, name, qualification, dob, phone, department, pass, prof_email, per_email);
        initial = "";
        name = "";
        qualification = "";
        dob = "";
        phone = "";
        department = "";
        pass = "";
        prof_email = "";
        per_email = "";
        k = 0;
    }
    read.close();
    return fil;
}
