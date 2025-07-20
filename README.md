# ROCK the SHOP – Shop Management Simulation in C++

This project is a C++ application that simulates the management of a rock-themed shop. It allows managing employees, product stock, and orders through a console-based menu system. The app uses modern C++ features and STL containers to provide a clear and modular design.

## Overview

The application models the core functionalities of a retail management system, including:

- Employee management (add, update, delete, validate)
- Product stock management (multiple product types)
- Order processing and validation
- Reporting with sorting and filtering

**Note:** This is a local console simulation, not an online or web-based application.

## Core Classes and Concepts

- **Employee** (base class) with derived classes: Manager, Operator, Assistant  
- **Product** (base class) with derived classes: Clothes, Disk, Vintage_Disk  
- **Order** class representing customer orders with product-quantity pairs  

## Features

- Validation of employee data (CNP, age, birthday checks)  
- Calculation of employee seniority (years of service)  
- Stock management including quantity and product details  
- Order queue management with order validation against stock availability  
- Modular menu-driven interface using `switch` statements  
- Exception handling for invalid input and business logic errors  
- Use of STL containers: `vector`, `queue`, and pairs  
- Modern C++ features: lambdas, `auto` keyword, range-based loops  
- Time functions (`<ctime>`) for date calculations  

## Code Structure

| File               | Description                                            |
|--------------------|--------------------------------------------------------|
| `main.cpp`         | Main program with the menu system and STL vectors      |
| `Employee.*`       | Employee base and derived classes                       |
| `Product.*`        | Product base and derived classes                        |
| `Order.*`          | Order class and related processing                      |
| `EmployeeGestion.*`| Functions for employee management menu                  |
| `StockGestion.*`   | Functions for stock management menu                     |
| `OrdersGestion.*`  | Order processing and validation functions               |
| `tests.*`          | Validation functions for CNP, age, birthday, etc.      |

## Data Input Formats

- **Employees:**  

- **Products:**  
- Clothes:  
  ```
  clothes id quantity price color brand
  ```
- Disks:  
  ```
  disk id quantity price cd/vinyl record_label date band album_name
  ```
- Vintage Disks:  
  ```
  vintage_disk id quantity price mint_flag rarity_coefficient
  ```

- **Orders:**  

## How to Use

- Run the compiled executable from the console  
- Navigate the menus to manage employees, stock, or orders  
- Add, view, modify or delete entities via menu options  
- Orders are processed by assigning them to operators and validating product availability  

## Author

Mădălina Ioana Palade  
Faculty of Automatic Control and Computers  
Bucharest, Romania  

## License

This project is for academic purposes. Please credit the author if you use or adapt the code.
