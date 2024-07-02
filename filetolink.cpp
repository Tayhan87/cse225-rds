#ifndef FILETOLINK_H
#define FILETOLINK_H

#include <iostream>
#include <fstream>
#include "coursename.cpp"
#include "coursedetail.cpp"
using namespace std;

class filetolink {
public:
    coursename nametolist() {
        ifstream read("E:\\CPP\\Project 2.0\\cse225-rds\\coursename.txt");
        if (!read.is_open()) {
            cout << "File could not be found." << endl;
            return coursename();
        }
        coursename c;
        string s, id = "",department="", name = "", code = "";
        int k = 0;
        while (getline(read, s)) {
            for (char ch : s) {
                if (ch == ',') {
                    k++;
                } else if (k == 0) {
                    id += ch;
                } else if (k == 1) {
                    department += ch;
                } else if (k == 2) {
                    name += ch;
                }else if (k == 2) {
                    code += ch;
                }
            }
            c.insertcourse(id,department, name, code);
            id = "";
            department="";
            name = "";
            code = "";
            k = 0;
        }
        read.close();
        return c;
    }

coursedetail detailtolist() {
    ifstream read2("coursedetail.txt");
    if (!read2.is_open()) {
        cout << "File could not be found." << endl;
        return coursedetail();
    }

    coursedetail c;
    string str, id = "", section = "", days = "", timing = "", room = "", faculty = "", credit = "";
    int k = 0;
    while (getline(read2, str)) {
        k = 0; // reset counter for each new line
        id = section = days = timing = room = faculty = credit = ""; // reset all fields

        for (char ch : str) {
            if (ch == ',') {
                k++;
            } else {
                if (k == 0) id += ch;
                else if (k == 1) section += ch;
                else if (k == 2) days += ch;
                else if (k == 3) timing += ch;
                else if (k == 4) room += ch;
                else if (k == 5) faculty += ch;
                else if (k == 6) credit += ch;
            }
        }
        c.insertcourse(id, section, days, timing, room, faculty, credit);
    }
    read2.close();
    return c;
}


};

#endif
