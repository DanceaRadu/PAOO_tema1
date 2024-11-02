#include "Student.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>

Student::Student(const std::string& name, int id): name(name), studentId(id) {}

Student::Student(const Student& other) {
    name = other.name;
    studentId = other.studentId;
    
    for(const auto& gradePtr : other.grades) {
        if(gradePtr) {
            grades.push_back(new Grade(*gradePtr));
        }
    }

    std::cout << "Copy constructor called for student: " << name << std::endl;
}

Student::Student(Student&& other) noexcept {
    name = std::move(other.name);
    studentId = other.studentId;
    grades = std::move(other.grades);

    other.name = "";
    other.studentId = 0;
    std::cout << "Move constructor called for student: " << name << std::endl;
}

//4. When a Student is destroyed, the memory of the grades gets freed as well 
Student::~Student() {
    std::cout << "Destructor called for student: " << name << std::endl;
    for (auto& grade : grades) {
        delete grade;
    }
    grades.clear();
}

void Student::addGrade(Grade* grade) {
    if(grade != nullptr) {
        grades.push_back(grade);
    }
}

void Student::listGrades() const {
    for(const auto& grade: grades) {
        std::cout << "Grade: " << grade->getGrade() << " (" << grade->getCourseName() << ")" <<std::endl;
    }
}

void Student::removeGradeById(int id) {
    auto it = std::find_if(grades.begin(), grades.end(), [&](Grade* grade) {
        return grade->getId() == id;
    });

    if (it != grades.end()) {
        delete *it;
        grades.erase(it);
        std::cout << "Grade with id = " << id << " was deleted from student with name = "<< name << std::endl;
    } else {
        std::cout << "Grade with id = " << id << " was not found." << std::endl;
    }
}

void Student::display() const {
    std::cout << "Student " << name << " has the following grades" << std::endl;
    listGrades();
    std::cout << std::endl;
}

void Student::setName(const std::string& newName) {
    name = newName;
}