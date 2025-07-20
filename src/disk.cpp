#include "../headers/disk.h"

Disk::Disk(string name, int number_of_pieces, float base_price, int id, string type, string record_house, string date, string band, string album_name): Product(name, number_of_pieces, base_price, id){
    this->type = type;
    this->record_house = record_house;
    this->date = date;
    this->band = band;
    this->album_name = album_name;
}

Disk::Disk(const Disk &d){
    name = d.name;
    number_of_pieces = d.number_of_pieces;
    base_price = d.base_price;
    id = d.id;
    type = d.type;
    record_house = d.record_house;
    date = d.date;
    band = d.band;
    album_name = d.album_name;
}

void Disk::input(istream &file){
    Product::input(file);
    file >> type >> record_house >> date >> band >> album_name;
}

void Disk::output(ostream &file) const{
    Product::output(file);
    file << type << " " << record_house << " " << date << " " << band << " " << album_name <<"\n";
}

float Disk::getPrice() const{
    return (base_price + delivery_price);
}

string Disk::getType() const{
    return type;
}

string Disk::getRecordHouse() const{
    return record_house;
}

string Disk::getDate() const{
    return date;
}

string Disk::getBand() const{
    return band;
}

string Disk::getAlbumName() const{
    return album_name;
}

float Disk::getBasePrice() const{
    return base_price;
}


