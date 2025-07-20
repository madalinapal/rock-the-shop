#include <iostream>
#include <string>
#pragma once

using namespace std;

class Product{
    protected:
        string name;
        int id;
        int number_of_pieces;
        float base_price;
    public:
        Product() = default;
        Product(string name, int number_of_pieces, float base_price, int id);
        Product(const Product &p);
        virtual float getPrice() const = 0;
        string getName() const;
        int getNumberOfPieces() const;
        virtual float getBasePrice() const;
        int getID() const;
        virtual ~Product() = default;
        virtual void input(istream &);
        virtual void output(ostream &) const;
        friend istream& operator>>(istream &in, Product &p);
        friend ostream& operator<<(ostream &out, const Product &p);
        void setName(string name);
        void setNumberOfPieces(int number_of_pieces);
};