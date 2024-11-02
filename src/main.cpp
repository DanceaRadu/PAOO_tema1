#include "./../include/Grade.hpp"
#include "./../include/Student.hpp"
#include <iostream>

int main() {

    Student student1("Radu Dancea", 1);

    student1.addGrade(
        new Grade(1, 10, "ALGEBRA")
    );
    student1.addGrade(
        new Grade(2, 5, "CD")
    );
    student1.addGrade(
        new Grade(3, 7, "CHS")
    );

    student1.display();

    student1.removeGradeById(2);
    std::cout << std::endl;

    student1.display();
    
    return 0;
}