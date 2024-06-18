#ifndef WRITEFILE_H
#define WRITEFILE_H

#include <iostream>
#include <fstream>
#include"coursename.cpp"
using namespace std;

template<class t1, class t2, class t3>
class writingfile{

public:
    void writecoursename(coursename<t1, t2, t3> &cname) {
        ofstream file("E:\\CPP\\Project 2.0\\RDS\\test.txt");
        typename coursename<t1, t2, t3>::node* temp = cname.getCourselist();

        while (temp != nullptr) {
            file << temp->id << "," << temp->name << "," << temp->code<< endl;
            temp = temp->next;
        }
        file.close();
    }
};

#endif

