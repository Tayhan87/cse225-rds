#ifndef COURSEDETAIL_H
#define COURSEDETAIL_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class coursedetail {
public:
    struct node {
        string id;
        string section;
        string days;
        string timing;
        string room;
        string faculty;
        string credit;
        node* next;
        node(const string& id_, const string& section_, const string& days_, const string& timing_, const string& room_, const string& faculty_, const string& credit_)
            : id(id_), section(section_), days(days_), timing(timing_), room(room_), faculty(faculty_), credit(credit_), next(nullptr) {}
    };

private:
    node* courselist;
    node* currentlocation;
    int length;

public:
    coursedetail() : courselist(nullptr), currentlocation(nullptr), length(0) {}

    ~coursedetail() {
        while (courselist != nullptr) {
            node* temp = courselist;
            courselist = courselist->next;
            delete temp;
        }
    }

    void insertcourse(const string& a, const string& b, const string& c, const string& d, const string& e, const string& f, const string& g) {
        node* temp = new node(a, b, c, d, e, f, g);
        temp->next = courselist;
        courselist = temp;
        length++;
    }

    void deletecourse(const string& a) {
        node* temp = courselist;
        node* prev = nullptr;
        while (temp != nullptr && temp->id != a) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) return; // Course not found
        if (prev == nullptr) { // Deleting the first node
            courselist = courselist->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
        length--;
    }

    int getlength() const {
        return length;
    }

    bool getcourse(string& a, string& b, string& c, string& d, string& e, string& f, string& g) {
        if (currentlocation == nullptr) {
            currentlocation = courselist;
        } else {
            currentlocation = currentlocation->next;
        }

        if (currentlocation == nullptr) return false;

        a = currentlocation->id;
        b = currentlocation->section;
        c = currentlocation->days;
        d = currentlocation->timing;
        e = currentlocation->room;
        f = currentlocation->faculty;
        g = currentlocation->credit;
        return true;
    }

    void reset() {
        currentlocation = nullptr;
    }

    node* getCourselist() const {
        return courselist;
    }
};

#endif
