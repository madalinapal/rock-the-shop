#include "../headers/reports.h"

void mostOrders(vector<Operator*> &operators){
    ofstream file4("output/reports.txt");
    Operator* max = operators[0];
    for(auto it = operators.begin(); it != operators.end(); it++){
        if((*it)->getOrders().size() > max->getOrders().size()){
            max = *it;
        }
    }
    file4 << "Most orders operator: " << max->getLastName() << " " << max->getFirstName() << endl;
}

void top3ValuableOrders(vector<Operator*> &operators){
    ofstream file4("output/reports.txt");
    sort(operators.begin(), operators.end(), [](Operator* a, Operator* b) {
        return a->getOrdersValue() > b->getOrdersValue();  
    });
    file4 << "Top 3 most valuable operators:\n";
    int count = 0;
    for (auto& op : operators) {
        if (count == 3) break;  
        file4 << "Operator with value: " << op->getOrdersValue() << " " << op->getLastName() << " " << op->getFirstName() << endl;
        count++;
    }
}

void top3BySalary(vector<Employee*> &employees){
    sort(employees.begin(), employees.end(), [](Employee* a, Employee* b) {
        return a->getSalary() > b->getSalary();  
    });
   
    vector<Employee*> top3;
    int count = 0;
    for (auto& emp : employees) {
        if (count == 3) break;
        top3.push_back(emp);
        count++;
    }
    sort(top3.begin(), top3.end(), [](Employee* a, Employee* b) {
        if (a->getLastName() == b->getLastName()) {
            return a->getFirstName() < b->getFirstName();  
        }
        return a->getLastName() < b->getLastName(); 
    });
    ofstream file4("output/reports.txt");
    file4 << "Top 3 highest paid employees (sorted alphabetically by name):\n";
    for (auto& emp : top3) {
        file4 << emp->getSalary() << " " << emp->getLastName() << " " << emp->getFirstName() << endl;
    }
}

void Reporting(vector<Employee*> &employees, vector<Operator*> &operators){
    int option;
    do {
        cout << "\n=== ROCK the SHOP Reporting Menu ===\n";
        cout << "1. Most orders operator\n";
        cout << "2. Top 3 most valuable operators\n";
        cout << "3. Top 3 highest paid employees\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                mostOrders(operators);
                break;
            case 2:
                top3ValuableOrders(operators);
                break;
            case 3:
                top3BySalary(employees);
                break;
            case 4:
                return;
            default:
                cout << "Invalid option\n";
                break;
        }
    } while (option != 4);
}