//Simon N. Nganga - 2655389
#include <iostream>
#include "Business.h"
using namespace std;
#include <cstring>

business::business() {
    this->businessName=  new char[strlen("Undefined") + 1];
    strcpy(businessName, "Undefined");
    size = -1;
    NoOfEmployees = 0;
    for (int i = 0; i < 20; i++) {
        Employees[i] = NULL;
    }
}

business::business(const char* businessName, int size) {
    this->businessName = new char[strlen(businessName) + 1];
    strcpy(this->businessName, businessName);
    this->size = size;
    for (int i = 0; i < 20; i++) {
        Employees[i] = NULL;
    }
    this->NoOfEmployees = 0;
}

business ::business(const business &B)  {
    this->businessName = new char[strlen(B.businessName) + 1];
    strcpy(this->businessName, B.businessName);

    this->NoOfEmployees = B.NoOfEmployees;
    this->size = B.size;
    for (int i = 0; i < 20;i++) {
        if (B.Employees[i] != NULL)
            this->Employees[i] = new Employee(*B.Employees[i]);
        else
            this->Employees[i] = NULL;
    }
}

business& business::operator=(const business &B ) {
    if (this == &B)
        return *this;

    delete [] this->businessName;
    this->businessName = new char[strlen(B.businessName) + 1];
    strcpy(this->businessName, B.businessName);

    this->NoOfEmployees = B.NoOfEmployees;
    this->size = B.size;
    for (int i = 0; i < 20;i++) {
        delete this->Employees[i];
        if (B.Employees[i] != NULL)
        this->Employees[i] = new Employee (*B.Employees[i]);
        else
            this->Employees[i] = NULL;
    }
    return *this;
}

business::~business() {
    delete [] businessName;

    for (int i = 0; i < 20; i++) {
        delete Employees[i];
    }
}

void business::setBusinessName(const char*businessName) {
    delete [] this->businessName;
    this->businessName = new char[strlen(businessName) + 1];
    strcpy(this->businessName,businessName);
}
void business::setBusinessSize(int size) {
    this->size = size;
}
int business::getBusinessSize() {
    return this->size;
}
const char* business::getBusinessName() {
    return this->businessName;
}
int business::getNoOfEmployees() {
    return this->NoOfEmployees;
}

void business::addEmployee(const char* firstName, const char* lastName, int SSN) {
    if (getNoOfEmployees() < 20) {
        Employee *employee = new Employee(firstName, lastName);
        employee->setSSN(SSN);
        Employees[NoOfEmployees] = employee;
        NoOfEmployees++;
    }
    else {
        cout<<"Cannot add more employees."<<endl;
    }
}

void business::printBusiness() {
    cout<<getBusinessName()<<" | Size: "<<getBusinessSize()<<" m^2 | Employees: "<<getNoOfEmployees()<<endl;
}

void business::printBusinessEmployees() {
    cout<<getBusinessName()<<" | Size: "<<getBusinessSize()<<" m^2 | Employees: "<<endl;
    for (int i = 0; i < getNoOfEmployees();i++) {
        Employees[i]->printEmployee();
    }
}

int  business::getType(){
    return -1; //this function will be overridden
 }

void business::searchByName(const char *keyword) {
    for (int i = 0; i < getNoOfEmployees(); i++) {
        if (Employees[i]->checkName(keyword) == true) {
            Employees[i]->printEmployee();
        }
    }
}

bool business::checkSuitability(const int requiredSeats) {
    return false;//this function will be overriden
}




