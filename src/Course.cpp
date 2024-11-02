#include "Course.hpp"
#include <iostream>
#include <string>

Course::Course(const std::string& courseName, const std::string& code): courseName(courseName), courseCode(code) {}

Course::Course(const Course& other) {
    courseName = other.courseName;
    courseCode = other.courseCode;
    std::cout << "Copy constructor called for course: " << courseName << std::endl;
}

Course::Course(Course&& other) noexcept {
    courseName = std::move(other.courseName);
    courseCode = std::move(other.courseCode);

    other.courseName = "";
    other.courseCode = "";

    std::cout << "Move constructor called for course: " << courseName << std::endl;
}

Course::~Course() {
    std::cout << "Destructor called for course: " << courseName << std::endl;
}

std::string Course::getCourseName() const {
    return courseName;
}

std::string Course::getCourseCode()const {
    return courseCode;
}