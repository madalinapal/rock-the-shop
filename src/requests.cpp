#include "../headers/requests.h"
#include <cassert>

void readOrders(queue<Order*> &orders, vector<Product*> &products) {
    ifstream file3("data/orders.txt");
    ofstream errors("output/errors.txt");
    int number_of_orders;
    file3 >> number_of_orders;
    
    for(int i = 0; i <= number_of_orders; i++){
        Order aux;
        try{
            aux.input(file3);
            aux.checkValidity(products);
            orders.push(&aux);
        }
        catch(const std::invalid_argument& e){
            errors << e.what() << " ";
            errors << "Order " << i << " is invalid" << endl;
        }
    }
}


void Requests(queue<Order*> &orders, vector<Operator*> &operators, vector<Product*> &products) {
    int option;
    do {
        cout << "\n=== Requests Menu ===\n";
        cout << "1. Read Orders\n";
        cout << "2. Asign Orders\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> option;
        switch(option) {
            case 1:
                {
                    readOrders(orders, products);
                    break;
                }
            /*case 2:
                {
                    int i = 0;
                    while(!orders.empty()){
                        Order *aux = orders.front();
                        orders.pop();
                        asignOrder(operators, *aux, products);
                        cout << "Order " << i + 1 << " asigned\n";
                        i ++;
                    }
                    cout << "All orders asigned\n";
                    break;
                }*/
            case 3:
                cout << "Exit the application.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (option != 3);
}