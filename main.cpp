#include <iostream>
#include <fstream>
#include "headers/employees_gestion.h"
#include "headers/stock_gestion.h"
#include "headers/order.h"
#include "headers/requests.h"
#include "headers/reports.h"

using namespace std;

int main(){
   
    vector<Employee*> employees;
    vector<Operator*> operators;
    vector<Product*> products;
    queue<Order*> orders;
    
    int option;

    do {
        cout << "\n=== ROCK the SHOP Management Menu ===\n";
        cout << "1. Employees Gestion\n";
        cout << "2. Stock Gestion\n";
        cout << "3. Orders processing\n";
        cout << "4. Reporting\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                EmployeeGestion(employees, operators);
                break;
            case 2:
                StockGestion(products);
                break;
            case 3:
                Requests(orders, operators, products);
                break;
            case 4:
                Reporting(employees, operators);
                break;
            case 5:
                cout << "Exit the application.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (option != 5);
    
    return 0;
}