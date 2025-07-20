#include <iostream>
#include <string>
#pragma once
using namespace std;

class Employee {
    protected:
    string type;
        string ID;
        string first_name;
        string last_name;
        string CNP;
        string hire_date;
        int years_of_service; 
        const float base_salary = 3500;
    public:
        Employee() = default;
        Employee(string ID, string first_name, string last_name, string CNP, string hire_date);
        string getID() const;
        string getFirstName() const;
        string getLastName() const;
        string getCNP() const;
        string getHireDate() const;
        int getYearsOfService() const;
        virtual ~Employee() = default;
        virtual float getSalary() const = 0;
        virtual void input(istream &);
        virtual void output(ostream &) const;
        bool operator==(const Employee &e);
        virtual void setLastName(string newLastName);
};