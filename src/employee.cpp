#include "../headers/employee.h"
#include "../headers/tests.h"

Employee::Employee(string ID, string first_name, string last_name, string CNP, string hire_date){
    this->ID = ID;
    this->first_name = first_name;
    this->last_name = last_name;
    this->CNP = CNP;
    this->hire_date = hire_date;
}

void Employee::input(istream &file){
    file >> ID >> first_name >> last_name >> CNP >> hire_date;
    if(!CNP_validation(CNP)){
        throw std::invalid_argument("Invalid CNP!");
    }
    if(!is18(CNP)){
        throw std::invalid_argument("The employee must be at least 18 y.o!");
    }
    years_of_service = years_difference(hire_date);
}

void Employee::output(ostream &file) const{
    file<< ID << " " << first_name << " " << last_name << " " << CNP << " " << hire_date << " " << years_of_service << " " << base_salary << " ";
}

string Employee::getID() const{
    return ID;
}
        
string Employee::getFirstName() const{
    return first_name;
}
    
string Employee::getLastName() const{
    return last_name;
}

string Employee::getCNP() const{
    return CNP;
}
    
string Employee::getHireDate() const{
    return hire_date;
}

int Employee::getYearsOfService() const{
    return years_of_service;
}

bool Employee::operator==(const Employee &e){
    return ID == e.ID;
}

void Employee::setLastName(string newLastName){
    last_name = newLastName;
}