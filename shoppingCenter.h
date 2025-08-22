//Simon N. Nganga - 2655389

#ifndef SHOPPINGCENTER_H
#define SHOPPINGCENTER_H

#include "Business.h"

class shoppingCenter{
private:
    char *Name;
    int noOfBusinesses;
protected:
    business *Businesses[50];
public:
    shoppingCenter();
    shoppingCenter(const char *);
    shoppingCenter& operator=(const shoppingCenter& );
    shoppingCenter(const shoppingCenter& );
    ~shoppingCenter();
    const char *getName();
    void setName(const char *);
    int getnoofBusinesses();
    void addBusiness(const char *, int ,int );
    void printBusiness();
    void printBusinessesEmployees();
    void printShopsStatistics();
    void printShopsByType(int );
    void printSuitableRestaurants(int );
    void searchByEmployeesName(const char *);//search for employees by keyword provided
    void printLargestBusiness();//print the details of the largest business in size in m^2
    void addEmployeeToBusiness(const char* ,const char*, const char*, int );

};

#endif //SHOPPINGCENTER_H
