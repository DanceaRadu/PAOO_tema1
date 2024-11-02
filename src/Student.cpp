#include "Student.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>

Student::Student(const std::string& name, int id): name(name), studentId(id) {}

Student::Student(const Student& other) {
    name = other.name;
    studentId = other.studentId;
    courses = other.courses;
    std::cout << "Copy constructor called for student: " << name << std::endl;
}

Student::Student(Student&& other) noexcept {
    name = std::move(other.name);
    studentId = std::move(other.studentId);
    courses = std::move(other.courses);

    other.name = "";
    other.studentId = 0;
    std::cout << "Move constructor called for student: " << name << std::endl;
}

Student::~Student() {
    std::cout << "Destructor called for student: " << name << std::endl;
}

void Student::enrollInCourse(Course* course) {
    if(course != nullptr) {
        courses.push_back(course);
    }
}

void Student::listCourses() const {
    for(const auto& course: courses) {
        std::cout << "Course: " << course->getCourseName() << course->getCourseCode() << ")" <<std::endl;
    }
}

void Student::removeCourseByCode(const std::string& code) {
    auto it = std::find_if(courses.begin(), courses.end(), [&](Course* course) {
        return course->getCourseCode() == code;
    });

    if (it != courses.end()) {
        delete *it;
        courses.erase(it);
        std::cout << "Course with code = " << code << " was deleted from student with name = "<< name << std::endl;
    } else {
        std::cout << "Course with code = " << code << " was not found." << std::endl;
    }
}