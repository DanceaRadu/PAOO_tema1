#include "./../include/Grade.hpp"
#include "./../include/Student.hpp"
#include <iostream>

int main() {

    Student student("Radu Dancea", 1);

    student.addGrade(
        new Grade(1, 10, "ALGEBRA")
    );
    student.addGrade(
        new Grade(2, 5, "CD")
    );
    student.addGrade(
        new Grade(3, 7, "CHS")
    );

    student.display();

    std::cout << "--------------------COPIED--------------------" << std::endl;
    Student studentCopy = student; 
    studentCopy.setName("Copied Dancea Radu"); 
    
    std::cout << std::endl;
    student.removeGradeById(2);
    std::cout << std::endl;

    student.display();
    //if the copy constructor of Student had not been overriden, this would've resulted in a seg fault
    //because the grades of studentCopy would've referenced the same memory as the grades of student
    studentCopy.display();

    std::cout << "--------------------MOVED--------------------" << std::endl;
    Student studentMoved = std::move(student);
    studentMoved.setName("Moved Dancea Radu");

    student.display();
    studentMoved.display();
    studentCopy.display();

    
    std::cout << "--------------------END OF PROGRAM DESTRUCTOR CALLS--------------------" << std::endl;
    return 0;
}