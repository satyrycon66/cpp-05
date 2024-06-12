#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("John", 50);
        std::cout << b1 << std::endl;

        // Test increment
        std::cout << "Incrementing grade..." << std::endl;
        b1++;
        std::cout << b1 << std::endl;

           // Test increment
        std::cout << "Incrementing grade..." << std::endl;
        ++b1;
        std::cout << b1 << std::endl;

        // Test decrement
        std::cout << "Decrementing grade..." << std::endl;
        --b1;
        std::cout << b1 << std::endl;

          // Test decrement
        std::cout << "Decrementing grade..." << std::endl;
        b1--;
        std::cout << b1 << std::endl;

        // Trying to create bureaucrat with invalid grade
        std::cout << "Trying to create bureaucrat with invalid grade..." << std::endl;
        Bureaucrat b2("Alice", 151); // This should throw GradeTooHighException

    } catch (const std::exception & e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}