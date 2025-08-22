# Shopping Centre Management System 🏢

This is a C++ command-line application that simulates a **Shopping Centre Management System**. It allows for the management of businesses, employees, and provides various functionalities to retrieve and display information about the shopping centre. The system is designed using object-oriented principles, with a clear class hierarchy representing different entities.

---


## Features

The system provides a menu-driven interface with the following functionalities:

* **Business Management:** Add new businesses, including shops and restaurants, to the shopping centre.
* **Employee Management:** Add new employees to specific businesses.
* **Data Display:**
    * Print all businesses with the number of employees.
    * Print all businesses with detailed employee information.
* **Statistics and Filtering:**
    * Get a count of each type of shop (e.g., Clothing, Technology).
    * Print details of shops based on a specific type.
    * Find and display restaurants that can accommodate a given number of seats.
* **Search Functionality:** Search for employees by a keyword in their first or last name.
* **Business Analysis:** Identify and print the details of the largest business (by size in m²).

---

## Implementation Details

The system is built on a set of interconnected C++ classes, designed to manage the data and behavior of a shopping centre.

### Class Structure

* **`ShoppingCentre`**: Manages a collection of businesses. It handles adding businesses, printing lists, and performing searches and statistical queries across the entire centre.
* **`Business`**: A base class for all businesses within the shopping centre. It stores common attributes like name, size, and a list of employees. It includes virtual functions to allow for polymorphic behavior.
* **`Employee`**: Represents an employee with a first name, last name, and a Social Security Number (SSN).
* **`Restaurant`**: Inherits from `Business` and adds a specific attribute for the number of seats. It has unique methods to check seat availability and override printing behavior.
* **`Shop`**: Inherits from `Business` and includes an enum to categorize different shop types (Clothing, Technology, etc.). It overrides methods to handle its specific properties.
