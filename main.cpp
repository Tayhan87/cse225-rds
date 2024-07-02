#include <iostream>
#include<fstream>
#include<vector>
#include "coursename.cpp"
#include"coursedetail.cpp"
#include "filetolink.cpp"
#include"hashtable.cpp"
#include"writefile.cpp"
#include "interface.h"
#include <csignal>
#include "main.h"

using namespace std;

void choosingafs() {

    Interface obj;
    int afsoption;
    cout << "\t\t\t Welcome to North South University" << endl << endl;
    cout << "\t Choose option: \n\n\t 1.Faculty \n\t 2.Student ";

    while (true) {
        cout << "\n\n\t Enter Your option: ";
        cin >> afsoption;
        if (afsoption >= 1 && afsoption <= 3)
            break;
        else
            cout << "\tWrong input. Please enter the right input";
    }

    switch (afsoption) {
    case 1:
        obj.facultypanel();
        break;

        /* case 2:
             studentpanel();
             break;*/

    }
}


int main()
{
   filetolink fl;
    auto c1=fl.nametolist();
    auto c2=fl.detailtolist();
    // fl.printdetail(c2);
    // fl.printname(c1);
    //writingfile file;
   // file.writecoursename(c1);

   for(int i=0;i<c1.getlength();i++)
   {
       string a,b,c,d;
       c1.getcourse(a,b,c,d);
       cout<<a<<" "<<b<<" "<<c<<" "<<endl;
   }
   cout<<endl<<endl;

   for(int i=0;i<c2.getlength();i++)
   {
       string a,b,c,d,e,f,g;
       c2.getcourse(a,b,c,d,e,f,g);
       cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<endl;
   }

   cout<<endl<<endl;


    c1.reset();
    c2.reset();

    CourseHashTable hashTable;

    hashTable.insertCourse(c1, c2);
    auto details=hashTable.getCourseDetail("c10");
    if (!details.empty())
    {
        for(const auto& detail: details)
        {
            cout << "Course ID: " << detail->id << endl;
            cout << "Section: " << detail->section << endl;
            cout << "Days: " << detail->days << endl;
            cout << "Timing: " << detail->timing << endl;
            cout << "Room: " << detail->room << endl;
            cout << "Faculty: " << detail->faculty << endl;
            cout << "Credit: " << detail->credit << endl<<endl;
        }

    }
      else{
          cout << "Course details not found for ID: c5"<< endl;
      }


    vector<string> keys = hashTable.getAllKeys();
    cout << "Course IDs in the hash table:" << endl;
    for (const string& key : keys) {
        cout << key << endl;
    }

      //choosingafs();

}


