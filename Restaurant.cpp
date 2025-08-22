//Simon N. Nganga - 2655389

#include <iostream>
#include "Restaurant.h"
#include "Business.h"
#include "Employee.h"
using namespace std;

restaurant::restaurant(){
    noOfSeats = 0;
}

restaurant::restaurant(const char *businessName, int size, int noOfSeats):business(businessName,size) {
    if (noOfSeats < 0)
        this->noOfSeats = 0;
    else
        this->noOfSeats = noOfSeats;
}

int restaurant::getNoOfSeats() const {
    return noOfSeats;
}

void restaurant::setNoOfSeats(int noOfSeats) {
    this->noOfSeats = noOfSeats;
}

bool restaurant::checkSuitability(const int requiredSeats) {
    if (this->noOfSeats >= requiredSeats)
        return true;

    return false;
}

void restaurant::printBusiness() {
    cout << "Restaurant | "
         << getBusinessName() << " | Size: "
         << getBusinessSize() << " m^2 | Seats: "
         << noOfSeats << " | Employees: "
         << getNoOfEmployees() << endl;
}


void restaurant::printBusinessEmployees() {
    cout << "Restaurant | Name: " << getBusinessName()
     << " | Size: " << getBusinessSize() << " m^2"
     << " | Seats: " << noOfSeats << endl;


    for (int i = 0; i < getNoOfEmployees(); i++) {
        Employees[i]->printEmployee();
    }

    if (getNoOfEmployees() == 0)
        cout << "No Employees." << endl;
}

int restaurant::getType(){return 0;}












