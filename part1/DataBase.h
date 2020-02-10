#ifndef __DATABASE_H_
#define __DATABASE_H_

#include <string>

class DataBase
{
public:
    virtual void add_student(std::string name) = 0;
    virtual bool add_course(int student_idx, char id[6] , float credit, char grade) = 0;
    virtual bool remove_student(int idx) = 0;
    virtual bool remove_course(int student_idx, int course_idx) = 0;
    virtual void display_students() = 0;
    virtual bool display_courses(int student_idx) = 0;
};

#endif // __DATABASE_H_
