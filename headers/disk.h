#include "product.h"
#pragma once

class Disk: public Product{
    private:
        string type; //CD/vinyl
        string record_house;
        string date;
        string band;
        string album_name;
        const float delivery_price = 5;
    public:
        Disk() = default;
        Disk(string name, int number_of_pieces, float base_price, int id, string type, string record_house, string date, string band, string album_name);
        Disk(const Disk &d);
        float getPrice() const override;
        string getType() const;
        string getRecordHouse() const;
        string getDate() const;
        string getBand() const;
        string getAlbumName() const;
        ~Disk() = default;
        void input(istream &) override;
        void output(ostream &) const override;
        float getBasePrice() const override;
};