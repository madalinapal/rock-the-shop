#pragma once
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

bool CNP_validation(string CNP);

int extract_year(string CNP);

int extract_month(string CNP);

int extract_day(string CNP);

int current_year();

int current_month();

int current_day();

bool is18(string CNP);

int years_difference(string date);

bool birthday(string CNP);