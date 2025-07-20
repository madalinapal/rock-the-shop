#include "../headers/order.h"

Order::Order(int nr_products, vector<pair<int, int>> products_ids, string order_date, string delivery_date, int minutes_to_complete, string status){
    this->nr_products = nr_products;
    this->products_ids = products_ids;
    this->order_date = order_date;
    this->delivery_date = delivery_date;
    this->minutes_to_complete = minutes_to_complete;
}

Order::Order(const Order &o){
    nr_products = o.nr_products;
    products_ids = o.products_ids;
    order_date = o.order_date;
    delivery_date = o.delivery_date;
    minutes_to_complete = o.minutes_to_complete;
}

string Order::getOrderDate() const{
    return order_date;
}

string Order::getDeliveryDate() const{
    return delivery_date;
}

time_t Order::getOrderDateInSeconds() const{
    struct tm tm;
    time_t t;
    strptime(order_date.c_str(), "%Y-%m-%d", &tm);
    t = mktime(&tm);
    return t;
}

time_t Order::getDeliveryDateTimeInSeconds() const{
    return getOrderDateInSeconds() + minutes_to_complete * 60;
}

void Order::input(istream &in){
    string product_type;
    int id, quantity;
    in >> order_date >> delivery_date >> minutes_to_complete;
    in >> nr_products;
    for(int i = 0; i < nr_products; i++){
        in >> id >> quantity;
        products_ids.push_back(make_pair(id, quantity));
    }
}

void Order::output(ostream &out) const{
    out << order_date << " " << delivery_date << " " << minutes_to_complete << " " << nr_products << " ";
    for(int i = 0; i < nr_products; i++){
        out << products_ids[i].first << " " << products_ids[i].second << " ";
    }
    out << "\n";
}

bool Order::checkValidity(const vector<Product*>& stock) const {
    int nr_disks = 0, nr_clothes = 0;
    float min_value = 0;
   
    for (int i = 0; i < nr_products; i++) {
        int product_id = products_ids[i].first;
        int quantity = products_ids[i].second;

        string product_type = findProductById(stock, product_id, quantity);
        if (product_type == "disc") {
            nr_disks = quantity;
        } else if (product_type == "haina") {
            nr_clothes = quantity;
        }
        min_value += getBasePriceById(stock, product_id) * quantity; 
    }

    if(nr_disks > 5){
        throw invalid_argument("Too many disks");
        return false;
    }
    if(nr_clothes > 5){
        throw invalid_argument("Too many clothes");
        return false;
    }
    if(min_value < 100){
        throw invalid_argument("Minimum value not reached");
        return false;
    }
    return true;
}

void Order::setStatus(string newStatus){
    status = newStatus;
}

float Order::getOrderPrice(vector<Product*> &stock){
    float price = 0;
    for(int i = 0; i < nr_products; i++){
        price += getPriceById(stock, products_ids[i].first) * products_ids[i].second;
    }
    return price;
}


