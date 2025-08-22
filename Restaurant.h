//Simon N. Nganga - 2655389

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
using namespace std;
#include "Business.h"

class restaurant:public business{
private:
    int noOfSeats;
public:
    restaurant();
    restaurant(const char*, int, int);
    restaurant(business* , int);
    int getNoOfSeats() const;
    void setNoOfSeats(int );
    bool checkSuitability(int );
    void printBusiness() ;
    void printBusinessEmployees() ;
    int getType() ;

};



#endif //RESTAURANT_H
