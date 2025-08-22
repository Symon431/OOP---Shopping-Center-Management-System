//Simon N. Nganga - 2655389

#ifndef BUSINESS_H
#define BUSINESS_H
#include "Employee.h"



class business {
private:
    char *businessName;
    int size;
    int NoOfEmployees;
protected:
     Employee *Employees[20];
public:
    business();
    business(const char*, int );
    business(const business& );
    business& operator=(const business& );
    virtual ~business();
    void setBusinessName(const char*);
    void setBusinessSize(int );
    int getBusinessSize();
    const char* getBusinessName();
    int getNoOfEmployees();
    void addEmployee(const char*, const char*, int );
    virtual void printBusiness();
    virtual void printBusinessEmployees();
    void searchByName(const char*);
    virtual int getType();
    virtual bool checkSuitability(const int requiredSeats);//only used when getType() is 0 for restaurant

};



#endif //BUSINESS_H
