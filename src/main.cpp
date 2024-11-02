#include "./../include/Course.hpp"
#include "./../include/Student.hpp"
#include <iostream>

int main() {

    Student student1("Radu Dancea", 1);

    

    std::cout << "Messages in hello:" << std::endl;
    hello.showMessages();

    // 5. Suprascrierea copy constructor-ului
    hello::Hello helloCopy = hello; // Apelul copy constructor-ului
    std::cout << '\n';
    std::cout << "Messages in helloCopy after copying hello:" << std::endl;
    helloCopy.showMessages();

    // 6. Crearea unui move constructor
    hello::Hello helloMoved = std::move(hello); // Apelul move constructor-ului
    std::cout << '\n';
    std::cout << "Messages in helloMoved after moving hello:" << std::endl;
    helloMoved.showMessages();

    return 0;
}