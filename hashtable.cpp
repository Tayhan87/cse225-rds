#ifndef COURSEHASHTABLE_H
#define COURSEHASHTABLE_H

#include <unordered_map>
#include <vector>
#include "coursename.cpp"
#include "coursedetail.cpp"
using namespace std;
class CourseHashTable
{
private:
    unordered_map<string, vector<coursedetail::node*>> hashTable;

public:
    void insertCourse(coursename &courseNames, coursedetail &courseDetails)
    {
        auto cnameNode = courseNames.getCourselist();
        auto cdetailNode = courseDetails.getCourselist();

        while (cnameNode != nullptr) {
            while (cdetailNode != nullptr) {
                if (cnameNode->id == cdetailNode->id) {
                    hashTable[cnameNode->id].push_back(cdetailNode);
                }
                cdetailNode = cdetailNode->next;
            }
            cnameNode = cnameNode->next;
            cdetailNode = courseDetails.getCourselist();
        }
    }

    vector<coursedetail::node*> getCourseDetail(const string &id)
    {
        if (hashTable.find(id) != hashTable.end()) {
            return hashTable[id];
        }
        return vector<coursedetail::node*>();
    }


    vector<string> getAllKeys() const
    {
        vector<string> keys;
        for (const auto& pair : hashTable) {
            keys.push_back(pair.first);
        }
        return keys;
    }
};

#endif
