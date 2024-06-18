#ifndef COURSEHASHTABLE_H
#define COURSEHASHTABLE_H

#include <unordered_map>
#include <vector>
#include "coursename.cpp"
#include "coursedetail.cpp"

template<class t1, class t2, class t3, class t4, class t5, class t6, class t7>
class CourseHashTable
{
private:
    unordered_map<t1, vector<typename coursedetail<t1, t2, t3, t4, t5, t6, t7>::node*>> hashTable;

public:
    void insertCourse(coursename<t1, t2, t3> &courseNames, coursedetail<t1, t2, t3, t4, t5, t6, t7> &courseDetails)
    {
        typename coursename<t1, t2, t3>::node* cnameNode = courseNames.getCourselist();
        typename coursedetail<t1, t2, t3, t4, t5, t6, t7>::node* cdetailNode = courseDetails.getCourselist();

        while (cnameNode != nullptr){

            while (cdetailNode != nullptr){

                if (cnameNode->id == cdetailNode->id){

                    hashTable[cnameNode->id].push_back( cdetailNode);
                }
                cdetailNode = cdetailNode->next;
            }
            cnameNode = cnameNode->next;
            cdetailNode = courseDetails.getCourselist();
        }
    }

    vector<typename coursedetail<t1, t2, t3, t4, t5, t6, t7>::node*> getCourseDetail(t1 id)
    {
        if (hashTable.find(id) != hashTable.end())
        {
            return hashTable[id];
        }
        return vector<typename coursedetail<t1, t2, t3, t4, t5, t6, t7>::node*>();
    }
};

#endif
