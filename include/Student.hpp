#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Course.hpp"

class Student {
    private:
        std::string name;
        int studentId;
        std::vector<Course*> courses;

    public:
        Student(const std::string& name, int id);
        void enrollInCourse(Course* course);
        void removeCourseByCode(const std::string& code);
        void listCourses() const;
        Student(const Student& other);
        Student(Student&& other) noexcept;
        ~Student();
};


#endif