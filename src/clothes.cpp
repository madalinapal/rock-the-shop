#include "../headers/clothes.h"

Clothes::Clothes(string name, int number_of_pieces, float base_price, int id, string color, string brand): Product(name, number_of_pieces, base_price, id){
    this->color = color;
    this->brand = brand;
}

Clothes::Clothes(const Clothes &c){
    name = c.name;
    number_of_pieces = c.number_of_pieces;
    base_price = c.base_price;
    id = c.id;
    color = c.color;
    brand = c.brand;
}

void Clothes::input(istream &file){
    Product::input(file);
    file >> color >> brand;
}

void Clothes::output(ostream &file) const{
    Product::output(file);
    file << color << " " << brand << "\n";
}

float Clothes::getPrice() const{
    return (base_price + delivery_price);
}

string Clothes::getColor() const{
    return color;
}

string Clothes::getBrand() const{
    return brand;
}

float Clothes::getBasePrice() const{
    return base_price;
}

