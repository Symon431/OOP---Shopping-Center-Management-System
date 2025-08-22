/* Simon N. Nganga – 2655389
I read and accept the submission rules and the extra rules specified
in each question. This is my own work that is done by myself only */

#include <iostream>
#include <cstring>
using namespace std;

#include "shoppingCenter.h"
#include "Employee.h"
#include "Business.h"
#include "Restaurant.h"
#include "Shop.h"

void menu() {

    cout << "--------------------------------------------------" << endl;
    cout << "1. Add a new business to the shopping centre." << endl;
    cout << "2. Add an employee to a business" << endl;
    cout << "3. Print all the businesses in the shopping centre with the number of employees in each business" << endl;
    cout << "4. Print all the businesses in the shopping centre with the details of employees in each business." << endl;
    cout << "5. Print the count of each type of shop in the shopping centre" << endl;
    cout << "6. Print the details of the shops whose type is a given type: " << endl;
    cout << "   (1: Clothing, 2: Technology, 3:Accessories, 4: Beauty)." << endl;
    cout << "7. Print the suitable restaurants based on a given required number of seats" << endl;
    cout << "8. Search for employees by name." << endl;
    cout << "9. Print the largest business in terms of size in the shopping centre." << endl;
    cout << "10. Exit." << endl;
    cout <<""<<endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Please select an option: " << endl;
}

int main() {
    shoppingCenter kalkanli_shopping_centre;
    int option;
    do {
        menu();
        cin >> option;
        switch (option) {
            case 1: {
                int businessType;
                cout << "Enter business type (0: Restaurant, 1: Clothing, 2: Technology, 3: Accessories, 4: Beauty):" << endl;
                cin >> businessType;

                cout << "Enter business name: " << endl;
                char businessName[100];
                cin >> businessName;

                cout << "Enter size of the business (in m^2): " << endl;
                int size;
                cin >> size;

                    kalkanli_shopping_centre.addBusiness(businessName, size, businessType);
                break;
            }
            case 2: {
                cout << "Enter target business Name: " << endl;
                char businessName[100];
                cin >> businessName;
                cout << "Enter employee first name: " << endl;
                char firstName[100];
                cin >> firstName;
                cout << "Enter employee last name: " << endl;
                char lastName[100];
                cin >> lastName;
                cout << "Enter  SSN: " << endl;
                int SSN;
                cin >> SSN;

                kalkanli_shopping_centre.addEmployeeToBusiness(businessName,firstName,lastName,SSN);
                break;
            }
            case 3: {
                kalkanli_shopping_centre.printBusiness();
                break;
            }
            case 4: {
                kalkanli_shopping_centre.printBusinessesEmployees();
                break;
            }
            case 5: {
                kalkanli_shopping_centre.printShopsStatistics();
                break;
            }
            case 6: {
                cout << "Enter shop type to print details (1: Clothing, 2: Technology, 3: Accessories, 4: Beauty):" << endl;
                int shopType;
                cin >> shopType;
                kalkanli_shopping_centre.printShopsByType(shopType);
                break;
            }
            case 7: {
                cout << "Enter required number of seats: " << endl;
                int noOfSeats;
                cin >> noOfSeats;
                kalkanli_shopping_centre.printSuitableRestaurants(noOfSeats);
                break;
            }
            case 8: {
                cout << "Enter search keyword for employee name: " << endl;
                char keyword[100];
                cin >> keyword;
                kalkanli_shopping_centre.searchByEmployeesName(keyword);
            }
            case 9: {
                kalkanli_shopping_centre.printLargestBusiness();
                break;
            }
            case 10: {
                cout << "BYE!!!" << endl;
                break;
            }
            default:{
                cout << "Invalid option." << endl;
                break;
            }
        }



    }while (option != 10);





    return 0;
}