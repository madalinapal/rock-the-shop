#include "disk.h"
#include "clothes.h"
#include "vintage_disk.h"
#include <fstream>
#pragma once

void addProducts(vector<Product*> &products);

void removeProduct(vector<Product*> &products, int ID);

void printProduct(vector<Product*> &products, int ID);

void printProducts(vector<Product*> &products);

void StockGestion(vector<Product*> &products);

void substractProduct(vector<Product*>&products, int ID, int quantity);

string findProductById(const vector<Product*> &products, int ID, int quantity);

float getBasePriceById(const vector<Product*> &products, int ID);

float getPriceById(const vector<Product*> &products, int ID);