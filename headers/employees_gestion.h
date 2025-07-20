#include "operator.h"
#include "manager.h"
#include "assistant.h"
#include <fstream>
#pragma once

void addEmployees(vector<Employee*> &employees, vector<Operator*> &operators);

void addEmployee(vector<Employee*> &employees, string type);

void removeEmployee(vector<Employee*> &employees, string ID);

void printEmployee(vector<Employee*> &employees, string ID);

void printEmployees(vector<Employee*> &employees);

void modifiyEmployeesName(vector<Employee*> &employees, string ID, string newLastName);

void EmployeeGestion(vector<Employee*> &employees, vector<Operator*> &operators);



