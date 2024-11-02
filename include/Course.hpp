#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
    private:
        std::string courseName;
        std::string courseCode;

    public:
        Course(const std::string& name, const std::string& code);
        Course(const Course& other);
        Course(Course&& other) noexcept;
        ~Course();
        std::string getCourseName() const;
        std::string getCourseCode() const;
};

#endif