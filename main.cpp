#include <iostream>
#include<fstream>
#include<vector>
#include "coursename.cpp"
#include"coursedetail.cpp"
#include "filetolink.cpp"
#include"hashtable.cpp"
#include"writefile.cpp"

using namespace std;

int main()
{
    filetolink fl;
    auto c1=fl.nametolist();
    auto c2=fl.detailtolist();
    // fl.printdetail(c2);
    //fl.printname(c1);
    writingfile<string,string,string>file;
    file.writecoursename(c1);

   /* CourseHashTable<string, string, string, string, string, string, string> hashTable;
    hashTable.insertCourse(c1, c2);
    auto details=hashTable.getCourseDetail("c5");
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
      }*/

}


