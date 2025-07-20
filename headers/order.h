#include <iostream>
#include <string>
#include <vector>
#include "stock_gestion.h"
#pragma once

using namespace std;

class Order{
    protected:
        int nr_products;
        vector<pair<int,int>> products_ids;
        string order_date;
        string delivery_date;
        int minutes_to_complete;
        string status;
    public:
        Order() = default;
        Order(int nr_products, vector<pair<int,int>> products_ids, string order_date, string delivery_date, int minutes_to_complete, string status);
        Order(const Order &o);
        vector<Product*> getProducts() const;
        string getOrderDate() const;
        string getDeliveryDate() const;
        virtual ~Order() = default;
        void input(istream &);
        bool checkValidity(const vector<Product*>& stock) const;
        void output(ostream &) const;
        void setStatus(string newStatus);
        float getOrderPrice(vector<Product*> &stock);
        time_t getOrderDateInSeconds() const;
        time_t getDeliveryDateTimeInSeconds() const;
};