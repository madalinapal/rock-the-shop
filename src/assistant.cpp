#include "../headers/assistant.h"
#include "../headers/tests.h"

Assistant::Assistant(const Assistant &a): Employee(a){
}

void Assistant::input(istream &file){
    Employee::input(file);
}

void Assistant::output(ostream &file) const{
    Employee::output(file);
    file << coeficient << endl;
}

float Assistant::getSalary() const{
    if(extract_month(CNP) == current_month()){
        return ((100 * years_of_service) + base_salary * coeficient + 100);
    }
    else
        return ((100 * years_of_service) +base_salary * coeficient);
}

bool Assistant::operator==(const Assistant &a){
    return Employee::operator==(a);
}

void Assistant::setLastName(string newLastName){
    last_name = newLastName;
}