#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade too high";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade too low";
        }
    };

    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    Bureaucrat& operator++(); // Prefix increment
    Bureaucrat operator++(int); // Postfix increment
    Bureaucrat& operator--(); // Prefix decrement
    Bureaucrat operator--(int); // Postfix decrement
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif