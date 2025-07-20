#include "../headers/stock_gestion.h"   

void addProducts(vector<Product*> &products){
    string product_type;
    ifstream file2("data/products.txt");
    ofstream errors("output/errors.txt");
    int nrdisks = 0, nrclothes = 0, nrvintagedisks = 0;
    while(!file2.eof()){
        file2 >> product_type;
        if(product_type == "disc"){
                auto *aux = new Disk();
                try{
                    aux->setName(product_type);
                    aux->input(file2);
                    products.push_back(aux);
                    nrdisks ++;
                }
                catch(const std::invalid_argument& e){
                    errors << e.what() << endl;
                }
        }
        else if(product_type == "haina"){
                auto *aux = new Clothes();
                try{
                    aux->setName(product_type);
                    aux->input(file2);
                    products.push_back(aux);
                    nrclothes ++;
                }
                catch(const std::invalid_argument& e){
                    errors << e.what() << endl;
                }
        }
        else if(product_type == "vintage_disc"){
                auto *aux = new VintageDisk();
                try{
                    aux->setName(product_type);
                    aux->input(file2);
                    products.push_back(aux);
                    nrvintagedisks ++;
                }
                catch(const std::invalid_argument& e){
                    errors << e.what() << endl;
                }
        }
    }

    if (nrdisks == 0 || nrclothes == 0 || nrvintagedisks == 0){
        cout << "Not enough products" << endl;
    }
    file2.close();
    errors.close();
}

void removeProduct(vector<Product*> &products, int ID){
    for(int i = 0; i < products.size(); i++){
        if(products[i]->getID() == ID){
            products.erase(products.begin() + i);
            break;
        }
    }   
}

void substractProduct(vector<Product*>&products, int ID, int quantity){
    for(int i = 0; i < products.size(); i++){
        if(products[i]->getID() == ID){
            products[i]->setNumberOfPieces(products[i]->getNumberOfPieces() - quantity);
            break;
        }
    }
}

void printProduct(vector<Product*> &products, int ID){
    ofstream file2("ouput/products.txt");
    for(int i = 0; i < products.size(); i++){
        if(products[i]->getID() == ID){
            products[i]->output(file2);
            break;
        }
    }
}

void printProducts(vector<Product*> &products){
    ofstream file2("ouput/products.txt");
    for(int i = 0; i < products.size(); i++){
        products[i]->output(file2);
    }
}

void StockGestion(vector<Product*> &products){
    int action;
    do{
        cout << "\n=== Stock Gestion Menu ===\n";
        cout << "1. Add Products\n";
        cout << "2. Remove Product\n";
        cout << "3. Print Products\n";
        cout << "4. Print Product\n";
        cout << "5. Exit.\n";
        cout << "Choose an option: ";
        cin >> action;
        switch(action){
            case 1:
                {
                    addProducts(products);
                    break;
                }
            case 2:
                {
                    int ID;
                    cout << "Enter the ID of the product you want to remove: ";
                    cin >> ID;
                    removeProduct(products, ID);
                    break;
                }
            case 3:
                printProducts(products);
                break;
            case 4:
                {
                    int ID;
                    cout << "Enter the ID of the product you want to print: ";
                    cin >> ID;
                    printProduct(products, ID);
                    break;
                }
            case 5:
                cout << "Exit the application.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
    while(action != 5);
}



string findProductById(const vector<Product*> &stock, int ID, int quantity){
    for(size_t i = 0; i < stock.size(); i++){
        if(stock[i]->getID() == ID && stock[i]->getNumberOfPieces() >= quantity){
            return stock[i]->getName();
        }
    }
    return "Product not found";
}

float getPriceById(const vector<Product*> &stock, int ID){
    for(size_t i = 0; i < stock.size(); i++){
        if(stock[i]->getID() == ID){
            return stock[i]->getPrice();
        }
    }
    return -1;
}

float getBasePriceById(const vector<Product*> &stock, int ID){
    for(size_t i = 0; i < stock.size(); i++){
        if(stock[i]->getID() == ID){
            return stock[i]->getBasePrice();
        }
    }
    return -1;
}