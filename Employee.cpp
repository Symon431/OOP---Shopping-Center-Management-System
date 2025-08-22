//Simon N. Nganga - 2655389

#include <iostream>
#include <cstring>
using namespace std;
#include "Employee.h"

Employee::Employee(const char *firstName, const char *lastName) {
    this->firstName = new char[strlen(firstName ) + 1];
    strcpy(this->firstName, firstName);
    this->lastName = new char[strlen(lastName ) + 1];
    strcpy(this->lastName, lastName);
    this->SSN = -1;
}

Employee::Employee(const Employee &employee){
    this -> firstName = new char[strlen(employee.firstName) + 1];
    strcpy(this->firstName, employee.firstName);
    this->lastName = new char[strlen(employee.lastName) + 1];
    strcpy(this->lastName, employee.lastName);
    this->SSN = employee.SSN;
}

Employee& Employee::operator=(const Employee &employee) {
    if (this == &employee)
        return *this;

    delete [] this->firstName;
    this->firstName = new char[strlen(employee.firstName) + 1];
    strcpy(this->firstName, employee.firstName);

    delete []this->lastName;
    this->lastName = new char[strlen(employee.lastName) + 1];
    strcpy(this->lastName, employee.lastName);
    this->SSN = employee.SSN;
    return *this;
}

Employee::~Employee() {
    delete [] firstName;
    delete [] lastName;
}

void Employee::setSSN(int SSN) {this->SSN = SSN;}

void Employee::setfirstName(const char *firstName) {
    delete [] this->firstName;
    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->firstName, firstName);
}

void Employee::setlastName(const char *lastName) {
    delete [] this->lastName;
    this->lastName = new char[strlen(lastName) + 1];
    strcpy(this->lastName, lastName);
}

const char* Employee::getfirstName() const {return this->firstName;}

const char* Employee::getlastName() const {return this->lastName;}

int Employee::getSSN() const {return this->SSN;}

 bool Employee::checkName(const char *keyword) const {
        return strstr(firstName, keyword) || strstr(lastName, keyword);
    }

void Employee::printEmployee() {
    cout << firstName << " " << lastName << " | SSN: " << SSN << endl;
}
