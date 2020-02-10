#include "DataBaseLinkedList.h"

#include <cstring>

using namespace LinkedListData;

void DataBaseLinkedList::add_student(std::string name)
{
    students.add_last(Student{name, LinkedList<Course>()});
}

bool DataBaseLinkedList::add_course(int student_idx, char id[6] , float credit, char grade)
{
    Student* student;
    if(!(student = students.get(student_idx))) return false;

    Course course;

    memcpy(id, course.id, sizeof(char)*6);
    course.credit = credit;
    course.grade = grade;
    student->courses.add_last(course);

    return true;
}

bool DataBaseLinkedList::remove_student(int idx)
{
    return students.remove(idx);
}

bool DataBaseLinkedList::remove_course(int student_idx, int course_idx)
{
    Student* student;
    if(!(student = students.get(student_idx))) return false;

    student->courses.remove(course_idx);
    return true;
}

void DataBaseLinkedList::display_students()
{
    auto it = students.get_iter();
    Student* student;
    int i = 0;

    while((student = it.next()) != nullptr)
    {
        printf("%d:\t%s\n", i+1, student->name.c_str());
        i++;
    }
}

bool DataBaseLinkedList::display_courses(int student_idx)
{
    Student* student = students.get(student_idx);
    if(student == nullptr) return false;

    printf("student: %p\n", student);
    auto it = student->courses.get_iter();
    Course* course;
    int i = 0;

    while((course = it.next()) != nullptr)
    {
        printf("%d:\t%s\n\tcredit: %.1f\n\tgrade: %d\n", i+1, course->id, course->credit, course->grade );
        i++;
    }

    return true;
}
