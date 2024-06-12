#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    if (grade > 150)
        throw GradeTooHighException();
    else if (grade < 1)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade < 150)
        _grade++;
    else
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
    if (_grade > 1)
        _grade--;
    else
        throw GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator++() {
    incrementGrade();
    return *this;
}

Bureaucrat Bureaucrat::operator++(int) {
    Bureaucrat temp = *this;
    incrementGrade();
    return temp;
}

Bureaucrat& Bureaucrat::operator--() {
    decrementGrade();
    return *this;
}

Bureaucrat Bureaucrat::operator--(int) {
    Bureaucrat temp = *this;
    decrementGrade();
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}