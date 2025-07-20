#include "../headers/tests.h"

bool CNP_validation(string CNP){
    if(CNP.size() != 13){
        return false;
    }
    if(CNP[0] == '3' || CNP[0] == '4' || CNP[0] == '7' || CNP[0] == '8'){
        cout << "3.4.7.8" << endl;
        return false; // presupun ca nu mai exista persoane nascute intre 1800 si 1899
    }
    for(int i = 0; i < 13; i++){
        if(CNP[i] < '0' || CNP[i] > '9'){
            cout << "out of range" << endl;
            return false;
        }
    }
    return true;
}

int extract_year(string CNP){
    if(CNP_validation(CNP) == false){
        return -1;
    }
    string year = CNP.substr(1, 2);
    int year_int = stoi(year);
    if(CNP[0] == '1' || CNP[0] == '2')
        return 1900 + year_int;
    else
        return 2000 + year_int;
}

int extract_month(string CNP){
    if(CNP_validation(CNP) == false){
        return -1;
    }
    string month = CNP.substr(3, 2);
    int month_int = stoi(month);
    return month_int;
}

int extract_day(string CNP){
    if(CNP_validation(CNP) == false){
        return -1;
    }
    string day = CNP.substr(5, 2);
    int day_int = stoi(day);
    return day_int;
}

int current_year(){
    time_t tim = time(0);
    tm *gettime = localtime(&tim);
    int year = gettime->tm_year + 1900;
    return year;
}

int current_month(){
    time_t tim = time(0);
    tm *gettime = localtime(&tim);
    int month = gettime->tm_mon + 1;
    return month;
}

int current_day(){
    time_t tim = time(0);
    tm *gettime = localtime(&tim);
    int day = gettime->tm_mday;
    return day;
}

bool is18(string CNP){
    int year = extract_year(CNP);
    int month = extract_month(CNP);
    int day =  extract_day(CNP);
    if(current_year() - year < 18){
        return false;
    }
    else
        if(current_year() - year == 18){
            if(current_month() < month){
                return false;
            }
            else
                if(current_month() == month){
                    if(current_day() < day){
                        return false;
                    }
                }
    }
    return true;
}

int years_difference(string date){
    string syear = date.substr(0, 4);
    int year = stoi(syear);
    int month = stoi(date.substr(6, 2));
    int day = stoi(date.substr(9, 2));
    int years = current_year() - year;
    if(current_month() < month){
        years--;
    }
    else
        if(current_month() == month){
            if(current_day() < day){
                years--;
            }
        }
    return years;
}

bool birthday(string CNP){
    if(extract_month(CNP) == current_month() && extract_day(CNP) == current_day()){
        return true;
    }
    return false;
}