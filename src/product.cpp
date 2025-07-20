#include "../headers/product.h"

Product::Product(string name, int number_of_pieces, float base_price, int id){
    this->name = name;
    this->number_of_pieces = number_of_pieces;
    this->base_price = base_price;
    this->id = id;
}

Product::Product(const Product &p){
    name = p.name;
    number_of_pieces = p.number_of_pieces;
    base_price = p.base_price;
    id = p.id;
}

void Product::input(istream &file){
    file >> id >> number_of_pieces >> base_price;
}

void Product::output(ostream &file) const{
    file << name << " " << number_of_pieces << " " << base_price << " " << id << " ";
}

string Product::getName() const{
    return name;
}

int Product::getNumberOfPieces() const{
    return number_of_pieces;
}

float Product::getBasePrice() const{
    return base_price;
}

int Product::getID() const{
    return id;
}

istream& operator>>(istream &in, Product &p){
    p.input(in);
    return in;
}

ostream& operator<<(ostream &out, const Product &p){
    p.output(out);
    return out;
}

void Product::setName(string name){
    this->name = name;
}

void Product::setNumberOfPieces(int number_of_pieces){
    this->number_of_pieces = number_of_pieces;
}