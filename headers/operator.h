#include "employee.h"
#include <vector>
#include "order.h"
#pragma once

using namespace std;

class Operator: public Employee{
    private:
        const float coeficient = 1;
        vector<Order> orders;
        float orders_value = 0;
    public:
        Operator() = default;
        Operator(const Operator &);
        float getSalary() const override;
        void input(istream &) override;
        void output(ostream &) const override;
        ~Operator() = default;
        bool operator==(const Operator &o);
        void setLastName(string newLastName) override;
        vector<Order>& getOrders();
        void increaseOrdersValue(float value);
        float getOrdersValue() const;
};