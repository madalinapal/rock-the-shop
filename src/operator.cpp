#include "../headers/operator.h"
#include "../headers/tests.h"

Operator::Operator(const Operator &o): Employee(o){
    
}

void Operator::input(istream &file){
    Employee::input(file);
}

void Operator::output(ostream &file) const{
    Employee::output(file);
    file << coeficient << endl;
}

float Operator::getSalary() const{
    if(extract_month(CNP) == current_month()){
        return ((100 * years_of_service) + base_salary * coeficient + 100);
    }
    else
        return ((100 * years_of_service) + base_salary * coeficient);
}

bool Operator::operator==(const Operator &o){
   return Employee::operator==(o);
}

void Operator::setLastName(string newLastName){
    last_name = newLastName;
}

vector<Order>& Operator::getOrders() {
    return orders; 
}

void Operator::increaseOrdersValue(float value){
    orders_value += value;
}


float Operator::getOrdersValue() const{
    return orders_value;
}
