#include "employee.h"
#pragma once

class Manager: public Employee{
    private:
        const float coeficient = 1.25;
    public:
        Manager() = default;
        Manager(const Manager &);
        float getSalary() const override;
        void input(istream &) override;
        void output(ostream &) const override;
        bool operator==(const Manager &m);
        void setLastName(string newLastName) override;
        ~Manager() = default;
};