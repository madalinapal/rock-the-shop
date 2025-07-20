#include "../headers/vintage_disk.h"

VintageDisk::VintageDisk(string name, int number_of_pieces, float base_price, int id, bool mint, int rarity_coefficient): Product(name, number_of_pieces, base_price, id){
    this->mint = mint;
    this->rarity_coefficient = rarity_coefficient;
}

VintageDisk::VintageDisk(const VintageDisk &v){
    name = v.name;
    number_of_pieces = v.number_of_pieces;
    base_price = v.base_price;
    id = v.id;
    mint = v.mint;
    rarity_coefficient = v.rarity_coefficient;
}

void VintageDisk::input(istream &file){
    Product::input(file);
    file >> mint >> rarity_coefficient;
    if(rarity_coefficient < 1 || rarity_coefficient > 5)
        throw std::out_of_range("The rarity coefficient must be between 1 and 5!");
}

void VintageDisk::output(ostream &file) const{
    Product::output(file);
    file << mint << " " << rarity_coefficient << "\n";
}

float VintageDisk::getPrice() const{
    return (base_price + delivery_price + 15 * rarity_coefficient);

}

bool VintageDisk::getMint() const{
    return mint;
}

int VintageDisk::getRarityCoefficient() const{
    return rarity_coefficient;
}

float VintageDisk::getBasePrice() const{
    return base_price;
}


