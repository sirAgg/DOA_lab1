#include "DataBaseArray.h"

#include <stdio.h>
#include <cstring>

using namespace ArrayListData;

void DataBaseArray::add_student(std::string name)
{
    students.push_back(Student{name, std::vector<Course>()});
}

bool DataBaseArray::add_course(int student_idx, char id[6], float credit, char grade)
{
    if(student_idx >= students.size())
        return false;

    auto& courses = students[student_idx].courses;
    courses.push_back(Course());
    Course& course = courses[courses.size()-1];

    memcpy(id, course.id, sizeof(char)*6);
    course.credit = credit;
    course.grade = grade;

    return true;
}

bool DataBaseArray::remove_student(int student_idx)
{
    if(student_idx >= students.size())
        return false;

    students.erase(students.begin()+student_idx);

    return true;
}

bool DataBaseArray::remove_course(int student_idx, int course_idx)
{
    if(student_idx >= students.size())
        return false;

    auto& courses = students[student_idx].courses;

    if(course_idx >= courses.size())
        return false;

    courses.erase(courses.begin() + course_idx);

    return true;
}

void DataBaseArray::display_students()
{
    for(int i=0; i<students.size(); i++)
    {
        printf("%d:\t%s\n", i+1, students[i].name.c_str());
    }
}

bool DataBaseArray::display_courses(int student_idx)
{
    if(student_idx >= students.size())
        return false;
    auto& courses = students[student_idx].courses;

    for(int i=0; i < courses.size(); i++)
        printf("%d:\t%s\n\tcredit: %.1f\n\tgrade: %d\n", i+1, courses[i].id, courses[i].credit, courses[i].grade );

    return true;
}
