#include <iostream>
#include <string>
#include <typeinfo>

void print2(std::string months[]);

int main() {
    std::string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    print2(months);

    return 0;
}


void print2(std::string months[]) {
    for (int i = 0; i < 12 ; i++) {
        std::cout << months[i] << '\t';
    }
}