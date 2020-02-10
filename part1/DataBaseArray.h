#ifndef __DATABASEARRAY_H_
#define __DATABASEARRAY_H_

#include "DataBase.h"

#include <vector>
#include <string>

namespace ArrayListData
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
        std::vector<Course> courses;
    };
}

class DataBaseArray : public DataBase
{
public:
    void add_student(std::string name) override;
    bool add_course(int student_idx, char id[6], float credit, char grade) override;
    bool remove_student(int student_idx) override;
    bool remove_course(int student_idx, int course_idx) override;
    void display_students() override;
    bool display_courses(int student_idx) override;
private:
    std::vector<ArrayListData::Student> students;
};

#endif // __DATABASEARRAY_H_
