#include "product.h"
#pragma once

class VintageDisk: public Product{
    private:
        bool mint; 
        int rarity_coefficient; 
        const float delivery_price = 5;
    public:
        VintageDisk() = default;
        VintageDisk(string name, int number_of_pieces, float base_price, int id, bool mint, int rarity_coefficient);
        VintageDisk(const VintageDisk &v);
        float getPrice() const override;
        bool getMint() const;
        int getRarityCoefficient() const;
        ~VintageDisk() = default;
        void input(istream &) override;
        void output(ostream &) const override;
        float getBasePrice() const override;
};