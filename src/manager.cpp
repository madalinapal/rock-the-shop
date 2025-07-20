#include "../headers/manager.h"
#include "../headers/tests.h"

Manager::Manager(const Manager &m): Employee(m){
}

void Manager::input(istream &file){
    Employee::input(file);
}

void Manager::output(ostream &file) const{
    Employee::output(file);
    file << coeficient << endl;
}

float Manager::getSalary() const{
    return ((100 * years_of_service) + base_salary * coeficient);
}

bool Manager::operator==(const Manager &m){
    return Employee::operator==(m);
}

void Manager::setLastName(string newLastName){
    last_name = newLastName;
}
