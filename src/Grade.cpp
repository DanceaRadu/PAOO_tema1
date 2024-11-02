#include "Grade.hpp"
#include <iostream>
#include <string>

Grade::Grade(int id, int grade, const std::string& courseName): courseName(courseName), id(id), grade(grade) {}

Grade::Grade(const Grade& other) {
    courseName = other.courseName;
    id = other.id;
    grade= other.grade;
    std::cout << "Copy constructor called for grade with id: " << id << std::endl;
}

Grade::Grade(Grade&& other) noexcept {
    courseName = std::move(other.courseName);
    id = std::move(other.id);
    grade= std::move(other.grade);

    other.grade = 0;
    other.id = 0;
    other.courseName = "";

    std::cout << "Move constructor called for grade with id: " << id << std::endl;
}

Grade::~Grade() {
    std::cout << "Destructor called for grade with id: " << id << std::endl;
}

std::string Grade::getCourseName() const {
    return courseName;
}

int Grade::getGrade() const {
    return grade;
}

int Grade::getId() const {
    return id;
}
