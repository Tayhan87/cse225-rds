#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <functional>
#include "facultyinfolist.h"
#include "facultyinfofile.h"
#include "writefile.cpp"
#include "main.h"

using namespace std;

class Interface {
public:
    // Member functions
    void facultypanel();
    int alert_start();
    void panel(string &id, string &password);
    faculty_info_list getfacultylist();
    void facultyoptions(const string& id);
    void facultyinfo(const string& id);
    void faculty_edit_profile(const string& id);
    void edit_faculty_attribute(const string &id, const string &attributeName, function<void(faculty_info_list::node*, const string&)> editFunc);
    faculty_info_list::node* findFacultyProfile(const string id) ;
    void faculty_take_course(const string id);



};

#endif // INTERFACE_H
