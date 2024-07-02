#ifndef WRITEFILE_H
#define WRITEFILE_H

#include <iostream>
#include <fstream>
#include "facultyinfolist.h"

using namespace std;

class filewriter {
public:
    void writefaculty(faculty_info_list &faculty) {
        ofstream file("E:\\CPP\\Project 2.0\\cse225-rds\\facultyinfo.txt");
        if (!file.is_open()) {
            cerr << "Unable to open file for writing." << endl;
            return;
        }

        faculty_info_list::node* temp = faculty.getfacultylisthead();

        while (temp != nullptr) {

            file << temp->initial << ","
                 << temp->name << ","
                 << temp->qualification << ","
                 << temp->dob << ","
                 << temp->phone << ","
                 << temp->department << ","
                 << temp->pass << ","
                 << temp->prof_email << ","
                 << temp->per_email << endl;
                 temp = temp->next;
                cout<<"";
        }
        file.close();
    }
};

#endif // FILEWRITER_H
