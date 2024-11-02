#ifndef COURSE_H
#define COURSE_H

#include <string>

class Grade {
    private:
        int id;
        int grade;
        std::string courseName;
    

    public:
        Grade(int id, int grade, const std::string& courseName);
        Grade(const Grade& other);
        Grade(Grade&& other) noexcept;
        ~Grade();
        int getId() const;
        int getGrade() const;
        std::string getCourseName() const;
};

#endif