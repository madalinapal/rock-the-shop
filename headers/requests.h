#include "employees_gestion.h"
#include "stock_gestion.h"
#include "tests.h"
using namespace std;

//void asignOrder(vector<Operator*> &operators, Order &order, vector <Product*> &products);

void readOrders(queue<Order*> &orders, vector<Product*> &products);

void Requests(queue<Order*> &orders, vector<Operator*> &operators, vector<Product*> &products);