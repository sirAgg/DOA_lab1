#ifndef __DATABASELINKEDLIST_H_
#define __DATABASELINKEDLIST_H_

#include "DataBase.h"
#include "LinkedList.h"

namespace LinkedListData
{
    struct Course
    {
        char id[7] = "------"; // might change to std::string
        float credit;
        char grade;
    };

    struct Student
    {
        std::string name;
        LinkedList<Course> courses;
    };
}

class DataBaseLinkedList : public DataBase
{
public:
    void add_student(std::string name);
    bool add_course(int student_idx, char id[6] , float credit, char grade);
    bool remove_student(int idx);
    bool remove_course(int student_idx, int course_idx);
    void display_students();
    bool display_courses(int student_idx);
private:
    LinkedList<LinkedListData::Student> students;
};

#endif // __DATABASELINKEDLIST_H_
