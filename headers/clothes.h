#include "product.h"
#pragma once

class Clothes: public Product{
    private:
        string color;
        string brand;
        const float delivery_price = 20;
    public:
        Clothes() = default;
        Clothes(string name, int number_of_pieces, float base_price, int id, string color, string brand);
        Clothes(const Clothes &c);
        float getPrice() const override;
        string getColor() const;
        string getBrand() const;
        ~Clothes() = default;
        void input(istream &) override;
        void output(ostream &) const override;
        float getBasePrice() const override;
};