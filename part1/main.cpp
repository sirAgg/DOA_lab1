#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>

#include "timer.h"

#include "DataBaseLinkedList.h"
#include "DataBaseArray.h"

void test_database(DataBase* db, int n_students, int seed)
{
    srand(seed);
    Timer _t("Total");

    {// create students
        char name[] = "student00000";
        Timer t("Create Students");
        for(int i = 0; i<n_students; i++)
        {
            sprintf(name, "student%05d", i);
            db->add_student(name);
        }
    }

    {// create courses
        char course_name[6] = "TEST0";
        Timer t("Create Courses");
        for(int student_idx = 0; student_idx<n_students; student_idx++)
        {
            int n_courses = rand()%6;
            for(int j = 0; j<n_courses; j++)
            {
                course_name[4] = j+'0';
                float credit = (float)(rand()%100)/10.0f;
                char grade = (char)(rand()%5);
                db->add_course(student_idx, course_name, credit, grade);
            }
        }
    }

    {// remove some courses
        Timer t("Remove some courses");
        for(int i = 0; i<n_students/2; i++)
        {
            int student_idx = rand()%n_students;
            db->remove_course(student_idx, 0);
        }
    }

    {// remove some students
        Timer t("Remove some students");
        for(int i = 0; i<n_students/2; i++)
        {
            db->remove_student(i);
        }
    }

}

int main(int argc, char *argv[])
{
    DataBaseArray array_db;
    DataBaseLinkedList list_db;
    int n_students = 1000;
    int seed = 0;

    printf("\nTesting Array\n-----------------------\n");
    test_database(&array_db, n_students, seed);

    printf("\nTesting LinkedList\n-----------------------\n");
    test_database(&list_db, n_students, seed);

    // {
    //     DataBaseArray db;
    //     db.add_student("olle");
    //     db.add_student("pelle");
    //     db.add_student("kalle");
    //     db.add_student("nicklas");
    //     db.add_student("sigfrid");
    //     db.add_student("douglas");

    //     db.add_course(0, "D0040D", 7.5f, 0);
    //     db.add_course(1, "D0041D", 7.5f, 1);
    //     db.add_course(3, "D0042D", 7.5f, 3);
    //     db.add_course(5, "D0043D", 7.5f, 5);
    //     db.add_course(2, "D0044D", 7.5f, 2);
    //     db.add_course(4, "D0045D", 7.5f, 4);

    //     db.display_students();
    //     printf("\n");
    //     db.display_courses(4);

    //     printf("\nremoveing student:\n");
    //     db.remove_student(0);
    //     db.remove_student(0);
    //     printf("\n");

    //     db.display_students();
    //     printf("\n\nDisp courses:\n");
    //     db.display_courses(4);

    //     printf("\nadding another course:\n");
    //     db.add_course(4, "D0039D", 7.5f, 0);
    //     printf("\n");
    //     db.display_courses(4);


    //     printf("\nremoveing course:\n");
    //     db.remove_course(4,0);
    //     printf("\n");
    //     db.display_courses(4);
    // }

    // {
    //     LinkedList<int> l;
    //     l.add_first(0);
    //     l.add_first(1);
    //     l.add_first(2);
    //     l.add_first(3);

    //     l.remove(3);
    //     l.remove(3);
    // }

    return 0;
}
