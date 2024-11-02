#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Grade.hpp"

class Student {
    private:
        std::string name;
        int studentId;
        std::vector<Grade*> grades;

    public:
        Student(const std::string& name, int id);
        void addGrade(Grade* grade);
        void removeGradeById(int id);
        void listGrades() const;
        void display() const;
        Student(const Student& other);
        Student(Student&& other) noexcept;
        ~Student();
};


#endif