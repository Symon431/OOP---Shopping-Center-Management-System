//Simon N. Nganga - 2655389

#include <iostream>
using namespace std;
#include "Business.h"
#include "Employee.h"
#include "Shop.h"

shop::shop() {
    setBusinessName("Undefined");
    setBusinessSize(-1);
    this->type = None;
}

shop::shop(const char *businessName, const int size, const shopType type):business(businessName,size) {
    this->type = type;
}

shopType shop::getShopType()  {return this->type;}
void shop::setShopType(const shopType shopType) {this->type = shopType;}


void shop::printBusiness() {
    cout << getShopTypeName(getType()) << " | "
         << getBusinessName() << " | Size: " << getBusinessSize()
         << " m^2 | Employees: " << getNoOfEmployees() << endl;
}





void shop::printBusinessEmployees() {
    cout << getShopTypeName(getType()) << " | "
    << getBusinessName() <<" | Size: " << getBusinessSize()
    <<" m^2 | "
    <<" Employees: " << endl;

    for (int i = 0; i < getNoOfEmployees(); i++) {
        Employees[i]->printEmployee();
    }
    if (getNoOfEmployees() == 0)
        cout << "No Employees " << endl;
}

int shop::getType() {
    switch (getShopType()){
        case None:
            return -1;
        case ClothingShop:
            return 1;
        case TechnologyShop:
            return 2;
        case AccessoriesShop:
            return 3;
        case BeautyShop:
            return 4;
        default:
            return -1;
    }
}

const char* shop::getShopTypeName(int type) {
    switch (type) {
        case ClothingShop: return "Clothing";
        case TechnologyShop: return "Technology";
        case AccessoriesShop: return "Accessories";
        case BeautyShop: return "Beauty";
        default: return "None";
    }
}





