//Simon N. Nganga - 2655389

#include "shoppingCenter.h"
#include <iostream>
#include <cstring>

#include "Restaurant.h"
#include "Shop.h"
using namespace std;


shoppingCenter::shoppingCenter() {
    this->Name = new char[strlen("Undefined") + 1];
    strcpy(this->Name, "Undefined");
    noOfBusinesses = 0;
    for (int i = 0; i < 50; i++) {
        Businesses[i] = NULL;
    }
}

shoppingCenter::shoppingCenter(const char* Name) {

    this->Name = new char[strlen(Name) + 1];
    strcpy(this->Name, Name);
    this->noOfBusinesses = 0;
    for (int i = 0; i < 50; i++) {
        Businesses[i] = NULL;
    }
}

shoppingCenter& shoppingCenter::operator=(const shoppingCenter& shoppingCenter) {
    if (this == &shoppingCenter)
        return *this;
    delete [] this->Name;
    this->Name = new char[strlen(shoppingCenter.Name) + 1];
    strcpy(this->Name, shoppingCenter.Name);
    this->noOfBusinesses = shoppingCenter.noOfBusinesses;
    for (int i = 0; i < 50; i++) {
        if (shoppingCenter.Businesses[i] != NULL)
            Businesses[i] = new business(*shoppingCenter.Businesses[i]);
        else
            Businesses[i] = NULL;
    }
    return *this;
}

shoppingCenter::shoppingCenter(const shoppingCenter &shoppingCenter) {
    Name = new char[strlen(shoppingCenter.Name) + 1];
    strcpy(this->Name, shoppingCenter.Name);
    this->noOfBusinesses = shoppingCenter.noOfBusinesses;
    for (int i = 0; i < 50; i++) {
        if (shoppingCenter.Businesses[i] != NULL)
            this->Businesses[i] = new business(*shoppingCenter.Businesses[i]);
        else
            this->Businesses[i] = NULL;
    }
}

shoppingCenter::~shoppingCenter () {
    delete [] Name;

    for (int i = 0; i < noOfBusinesses; i++) {
        delete Businesses[i];

    }
}

const char* shoppingCenter:: getName() {
    return this->Name;
}

void shoppingCenter::setName(const char *Name) {
    delete [] this->Name;
    this->Name = new char[strlen(Name) + 1];
    strcpy(this->Name, Name);
}

int shoppingCenter::getnoofBusinesses() {
    return this->noOfBusinesses;
}

void shoppingCenter::addBusiness(const char* businessName, int size, int businessType) {
    if (noOfBusinesses >= 50) {
        cout<<"Cannot add more businesses."<<endl;
        return;
    }

    if (businessType == 0) {
        int nOOfSeats;
        cout << "Enter number of seats: " << endl;
        int noOfSeats;
        cin >> noOfSeats;
        Businesses[noOfBusinesses] = new restaurant(businessName, size, noOfSeats);
        noOfBusinesses++;
        cout << "Business  \""  << businessName << "\""" added. " << endl;

    }
    else if (businessType > 0 &&businessType < 5) {
        shopType type;
        switch (businessType) {
            case 1: type = ClothingShop;break;
            case 2: type = TechnologyShop;break;
            case 3: type = AccessoriesShop;break;
            case 4: type = BeautyShop;break;
            default: type = None;break;
        }
        Businesses[noOfBusinesses] = new shop(businessName, size,type);
        noOfBusinesses++;
        cout << "Business  \""  << businessName << "\""" added. " << endl;
    }

    else
        cout << "Invalid Type." << endl;
    }

void shoppingCenter::printBusiness() {
    for (int i = 0; i < noOfBusinesses; i++) {
        Businesses[i]->printBusiness();
    }
}

void shoppingCenter::printBusinessesEmployees() {
    for (int i = 0; i < noOfBusinesses; i++) {
        Businesses[i]->printBusinessEmployees();
    }
}

void shoppingCenter::printShopsStatistics() {

    int clothingShops = 0;
    int technologyShops = 0;
    int accessoriesShops = 0;
    int beautyShops = 0;
    for (int i = 0; i < noOfBusinesses; i++) {
        switch (Businesses[i]->getType()) {
            case 1: {
                clothingShops++;
                break;
            }
            case 2: {
                technologyShops++;
                break;
            }
            case 3: {
                accessoriesShops++;
                break;
            }
            case 4: {
                beautyShops++;
                break;
            }
        }
    }

        cout << "Clothing Shops: " << clothingShops << endl;
        cout << "Technology Shops: " << technologyShops << endl;
        cout << "Accessories Shops: " << accessoriesShops << endl;
        cout << "Beauty Shops: " << beautyShops << endl;
}

void shoppingCenter::printShopsByType(int type) {
    for (int i = 0; i < noOfBusinesses; i++) {
        if (Businesses[i]->getType() == type) {
            Businesses[i]->printBusiness();
        }
    }
}

void shoppingCenter::printSuitableRestaurants(int noOfSeats) {
    int found = 0;
    for (int i = 0; i < noOfBusinesses; i++) {
        if (Businesses[i]->getType() == 0) {
            if (Businesses[i]->checkSuitability(noOfSeats) == true) {
                Businesses[i]->printBusiness();
                found = 1;
            }
        }
    }
    if (found == 0)
        cout << "No suitable restaurant found." << endl;
}

void shoppingCenter::searchByEmployeesName(const char *keyword) {
    for (int i = 0; i < noOfBusinesses; i++) {
        Businesses[i]->searchByName(keyword);
    }
}

void shoppingCenter::printLargestBusiness() {
    business *largestBusiness = NULL;
    int largestSize = -1;
    if (noOfBusinesses > 0) {
        largestBusiness = Businesses[0];
        largestSize = Businesses[0]->getBusinessSize();
        for (int i = 1; i < noOfBusinesses; i++) {
            if (Businesses[i]->getBusinessSize() > largestSize) {
                largestBusiness = Businesses[i];
                largestSize = Businesses[i]->getBusinessSize();
            }
        }
        largestBusiness->printBusiness();
        return;
    }
    cout<<"Your shopping centre has no businesses."<<endl;
}

void shoppingCenter::addEmployeeToBusiness(const char * businessName, const char* firstName, const char* lastName, int SSN) {
    for (int i = 0; i < noOfBusinesses; i++) {
        if (strcmp(Businesses[i]->getBusinessName(),businessName) == 0) {
            Businesses[i]->addEmployee(firstName,lastName,SSN);
            cout << "Employee:\"""  " << firstName << " " << lastName << "\"""  added to " << businessName << endl;
            return;
        }
    }
    cout<<"Business not found."<<endl;
}





