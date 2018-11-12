#include <iostream>

struct Date {
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

void initDate(Date* date);
void setDate(Date* date);
void getDate(Date* date);

int main() {
    Date date;
    std::cout << "Initializing date...\n";
    initDate(&date);
    std::cout << "Default date is: \n";
    getDate(&date);
    std::cout << "Set a new date\n";
    setDate(&date);
    std::cout << "The new date:\n";
    getDate(&date);

    return 0;
}

void initDate(Date* date){
    date->day = 15;
    date->month = 6;
    date->year = 2018;
}

void setDate(Date* date){
    std::cout << "Enter year number (1111):" << '\n';
    std::cin >> date->year;
    //here we can add checking for a leap year
    std::cout << "Enter month number (1-12):" << '\n';
    std::cin >> date->month;
    //here we can add checking for a max number of day in month and year
    std::cout << "Enter day number (1-31):" << '\n';
    std::cin >> date->day;
}

void getDate(Date* date){
    std::cout << date->day << '.' << date->month << '.' << date->year << '\n';
}