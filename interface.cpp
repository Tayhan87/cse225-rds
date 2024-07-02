#include "interface.h"
#include "writefile.cpp"
#include <functional>
#include "main.h"
#include "coursename.cpp"
#include "filetolink.cpp"
#include "hashtable.cpp"

void Interface::facultypanel() {
    string id, password;
    panel(id, password);
    faculty_info_list faculty_profile = getfacultylist();

    while (!faculty_profile.login(id, password)) {
        cout << "Wrong ID or password. Try again." << endl;
        panel(id, password);
    }
    facultyoptions(id);
}

int Interface::alert_start() {
    int n;
    cout << "\n\t Choose option: \n\n\t 1.Continue \n\n\t 2.Go To Homepage \n\n\t Enter Your Option: ";
    cin >> n;
    return n;
}

void Interface::panel(string &id, string &password) {
    cout << "\n\n\n\t\t\t Welcome to North South University \n\n\n" << endl << endl;
    int n = alert_start();
    if (n == 1) {
        cout << "\n\n\t Enter Faculty Initial / Student ID: ";
        cin >> id;
        cout << "\n\t Password: ";
        cin >> password;
    } else if (n == 2) {
        choosingafs();
    }
}

faculty_info_list Interface::getfacultylist() {
    facultyinfofile flr;
    return flr.infotolist();
}

faculty_info_list::node* Interface::findFacultyProfile(const string id) {
    faculty_info_list faculty_profile = getfacultylist();
    faculty_info_list::node* profile = faculty_profile.getfacultylisthead();

    while (profile != nullptr) {
        if (profile->initial == id) {
            return profile;
        }
        profile = profile->next;
    }
    return nullptr;
}

void Interface::facultyoptions(const string &id) {
    cout << "\n\n\t Choose Option: \n\n\t 1. Personal Information \n\t 2. Take courses \n\n";
    int n;
    cout << "\t Enter Your Option: ";
    cin >> n;
    switch (n) {
    case 1:
        facultyinfo(id);
        break;
         case 2:
         faculty_take_course(id);
         break;
    }
}

void Interface::facultyinfo(const string &id) {
    auto profile = findFacultyProfile(id);
    if (profile == nullptr) {
        cout << "Profile not found." << endl;
        return;
    }

    cout << "\n\n\t\t\t Personal Information \n\n";
    cout << "\t Initial: " << profile->initial << endl;
    cout << "\t Full Name: " << profile->name << endl;
    cout << "\t Qualification: " << profile->qualification << endl;
    cout << "\t Birth of Date: " << profile->dob << endl;
    cout << "\t Phone Number: " << profile->phone << endl;
    cout << "\t Department: " << profile->department << endl;
    cout << "\t Professional Email Address: " << profile->prof_email << endl;
    cout << "\t Personal Email Address: " << profile->per_email << endl;

    cout << "\n\n\t Choose an Option: \n\n\t 1.Edit Profile \n\n\t 2.Back \n\n\t 3.Logout \n\n\t Enter an option: ";
    int n;
    cin >> n;

    switch (n) {
    case 1:
        faculty_edit_profile(id);
        break;
    case 2:
        facultyoptions(id);
        break;
    case 3:
        cout << "\n\n\t Successfully logged out. \n\n";
        choosingafs();
        break;
    }
}

void Interface::faculty_edit_profile(const string &id) {
    auto profile = findFacultyProfile(id);
    if (profile == nullptr) {
        cout << "Faculty not found." << endl;
        return;
    }

    cout << "\n\n\t What do you want to change? \n\n\t 1.Name \n\n\t 2.Date Of Birth \n\n\t 3.Phone Number \n\n\t 4.Personal Email \n\n\t 5.Back \n\n\t 6.Log out \n\n\t Enter Option: ";
    int n;
    cin >> n;
    switch (n) {
    case 1:
        edit_faculty_attribute(id, "Name", [](faculty_info_list::node* profile, const string &newValue) {
            profile->name = newValue;
        });
        break;
    case 2:
        edit_faculty_attribute(id, "Birthdate", [](faculty_info_list::node* profile, const string &newValue) {
            profile->dob = newValue;
        });
        break;
    case 3:
        edit_faculty_attribute(id, "Phone Number", [](faculty_info_list::node* profile, const string &newValue) {
            profile->phone = newValue;
        });
        break;
    case 4:
        edit_faculty_attribute(id, "Personal Email", [](faculty_info_list::node* profile, const string &newValue) {
            profile->per_email = newValue;
        });
        break;
    case 5:
        facultyoptions(id);
        break;
    case 6:
        choosingafs();
        break;
    }
}

void Interface::edit_faculty_attribute(const string &id, const string &attributeName, function<void(faculty_info_list::node*, const string &)> editFunc) {
    auto profile = findFacultyProfile(id);
    if (profile == nullptr) {
        cout << "Faculty not found." << endl;
        return;
    }

    string newValue;
    cout << "\n\n\t Current " << attributeName << ": "
         << (attributeName == "Name" ? profile->name : attributeName == "Birthdate" ? profile->dob : attributeName == "Phone Number" ? profile->phone : profile->per_email)
         << "\n\n\t New " << attributeName << ": ";
    cin.ignore();
    getline(cin, newValue);

    editFunc(profile, newValue);

    faculty_info_list faculty_profile = getfacultylist();
    filewriter fw;
    fw.writefaculty(faculty_profile);
    cout << "\n\n\t Your " << attributeName << " is successfully updated. \n\n\t";

    faculty_edit_profile(id);
}



void Interface::faculty_take_course(const string id)
{
    auto profile = findFacultyProfile(id);
    if (!profile) {
        cout << "Profile not found." << endl;
        return;
    }

    filetolink fl;
    auto cname = fl.nametolist();
    auto cdetail = fl.detailtolist();

    CourseHashTable hashTable;
    hashTable.insertCourse(cname, cdetail);

    for (int i = 0; i < cname.getlength(); i++) {
        string courseID, department, name, code;
        cname.getcourse(courseID, department, name, code);
        if (department == profile->department) {
            cout << courseID << "\t" << name << "\t" << code << endl;
        }
    }

    cout << "\t Which course do you want to take? Enter the course ID.";
    cout << endl << "Course ID: ";
    string courseID;
    cin >> courseID;

    auto details = hashTable.getCourseDetail(courseID);
    if (!details.empty()) {
        for (const auto &detail : details) {
            cout << "Course ID: " << detail->id << endl;
            cout << "Section: " << detail->section << endl;
            cout << "Days: " << detail->days << endl;
            cout << "Timing: " << detail->timing << endl;
            cout << "Room: " << detail->room << endl;
            cout << "Faculty: " << detail->faculty << endl;
            cout << "Credit: " << detail->credit << endl << endl;
        }
    } else {
        cout << "Course details not found for ID: " << courseID << endl;
    }
}
