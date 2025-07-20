#include "../headers/employees_gestion.h"

void addEmployees(vector<Employee*> &employees, vector<Operator*> &operators){
    string employee_type;
    ifstream file1("data/employees.txt");
    ofstream errors("output/errors.txt");

    if (!file1) {
        errors << "Eroare: Nu s-a putut deschide fișierul de intrare 'data/employees.txt'!" << endl;
        return;  
    }

   
    if (!errors) {
        errors << "Eroare: Nu s-a putut deschide fișierul de erori 'output/errors.txt'!" << endl;
        return;  
    }

    int nrmanagers = 0, nroperators = 0, nrassistants = 0;
    while(!file1.eof()){
        file1 >> employee_type;
        if(employee_type == "manager"){
                Manager aux;
                try{
                    aux.input(file1);
                    employees.push_back(new Manager(aux));
                    nrmanagers ++;
                }
                catch(const std::invalid_argument& e){
                    errors << e.what() << endl;
                }
        }
        else if(employee_type == "operator"){
                Operator aux;
                try{
                    aux.input(file1);
                    employees.push_back(new Operator(aux));
                    operators.push_back(new Operator(aux));
                    nroperators ++;
                }
                catch(const std::invalid_argument& e){
                    errors << e.what() << endl;
                }
        }
        else if(employee_type == "asistent"){
                Assistant aux;
                try{
                    aux.input(file1);
                    employees.push_back(new Assistant(aux));
                    nrassistants ++;
                }
                catch(const std::invalid_argument& e){
                    errors << e.what() << endl;
                }
        }
    }

     if (nrmanagers == 0 || nroperators < 3 || nrassistants == 0){
        cout << "Not enough employees" << endl;
    }
    file1.close();
    errors.close();
}

void addEmployee(vector<Employee*> &employees, string type){
    if(type == "manager"){
        Manager* aux = new Manager();
        try{
            aux->input(cin);
            employees.push_back(aux);
        }
        catch(const std::invalid_argument& e){
            cout << e.what() << endl;
        }
    }
    else if(type == "operator"){
        Operator* aux = new Operator();
        try{
            aux->input(cin);
            employees.push_back(aux);
        }
        catch(const std::invalid_argument& e){
            cout << e.what() << endl;
        }
    }
    else if(type == "assistant"){
        Assistant* aux = new Assistant();
        try{
            aux->input(cin);
            employees.push_back(aux);
        }
        catch(const std::invalid_argument& e){
            cout << e.what() << endl;
        }
    }
}

void removeEmployee(vector<Employee*> &employees, string ID){
    for(int i = 0; i < employees.size(); i++){
        if(employees[i]->getID() == ID){
            employees.erase(employees.begin() + i);
            break;
        }
    }   
}

void printEmployee(vector<Employee*> &employees, string ID){
    ofstream file3("output/employees.txt");
    for(int i = 0; i < employees.size(); i++){
        if(employees[i]->getID() == ID){
            employees[i]->output(file3);
            break;
        }
    }
}

void printEmployees(vector<Employee*> &employees){
    ofstream file3("output/employees.txt");
    for(int i = 0; i < employees.size(); i++){
        employees[i]->output(file3);
    }
}

void modifiyEmployeesName(vector<Employee*> &employees, string ID, string newLastName){
    for(int i = 0; i < employees.size(); i++){
        if(employees[i]->getID() == ID){
            employees[i]->setLastName(newLastName);
            break;
        }
    }
}

void EmployeeGestion(vector<Employee*> &employees, vector<Operator*> &operators){
    int action;
    do {
        cout << "\n=== Employees Gestion Menu ===\n";
        cout << "1. Add Employees\n";
        cout << "2. Add Employee\n";
        cout << "3. Remove Employee\n";
        cout << "4. Print Employees\n";
        cout << "5. Print Employee\n";
        cout << "6. Modify Employee's Name\n";
        cout << "7. Exit.\n";
        cout << "Choose an option: ";
        cin >> action;
        switch(action){
            case 1:
                addEmployees(employees, operators);
                break;
            case 2:
                {
                    string type;
                    cout << "Enter the type of the employee (manager/operator/assistant): ";
                    cin >> type;
                    addEmployee(employees, type);
                    break;
                }
            case 3:
                {
                    string ID;
                    cout << "Enter the ID of the employee you want to remove: ";
                    cin >> ID;
                    removeEmployee(employees, ID);
                    break;
                }
            case 4:
                printEmployees(employees);
                break;
            case 5:
                {
                    string ID;
                    cout << "Enter the ID of the employee you want to print: ";
                    cin >> ID;
                    printEmployee(employees, ID);
                    break;
                }
            case 6:
                {
                    string ID, newLastName;
                    cout << "Enter the ID of the employee you want to modify: ";
                    cin >> ID;
                    cout << "Enter the new last name: ";
                    cin >> newLastName;
                    modifiyEmployeesName(employees, ID, newLastName);
                    break;
                }
            case 7:
                cout << "Exiting Employees Gestion Menu" << endl;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    } while(action != 7);
}