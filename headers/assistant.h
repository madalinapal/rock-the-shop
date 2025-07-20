#include "employee.h"
#pragma once

class Assistant: public Employee{
    private:
        const float coeficient = 0.75;
    public:
        Assistant() = default;
        Assistant(const Assistant &);
        float getSalary() const override;
        void input(istream &) override;
        void output(ostream &) const override;
        ~Assistant() = default;
        bool operator==(const Assistant &a);
        void setLastName(string newLastName) override;
};