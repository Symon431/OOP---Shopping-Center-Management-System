//Simon N. Nganga - 2655389

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
private:
    char *firstName;
    char *lastName;
    int SSN;

public:
    Employee(const char *firstName, const char *lastName);

    void setfirstName(const char *firstName);
    void setlastName(const char *lastName);
    void setSSN(int SSN);
    const char* getfirstName() const;
    const char* getlastName() const;
    int getSSN() const;

    bool checkName(const char *) const;
    void printEmployee();

    Employee& operator=(const Employee& );
    Employee (const Employee& );

    ~Employee();

};


#endif //EMPLOYEE_H
