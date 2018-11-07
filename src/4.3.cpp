#include <iostream>

int main() {
    enum E1 {first};
    enum E2 {second, third, fourth, fifth, sixth, sevens, eights, ninth, tenth};

    std::cout << "Size of bool: " << "\t\t\t" << sizeof(bool) << '.' << '\n';
    std::cout << "Size of char: " << "\t\t\t" << sizeof(char) << '.' << '\n';
    std::cout << "Size of wchar_t: " << "\t\t" << sizeof(wchar_t) << '.' << '\n';
    std::cout << "Size of short int: " << "\t\t" << sizeof(short int) << '.' << '\n';
    std::cout << "Size of int: " << "\t\t\t" << sizeof(int) << '.' << '\n';
    std::cout << "Size of long int: " << "\t\t" << sizeof(long int) << '.' << '\n';
    std::cout << "Size of float: " << "\t\t\t" << sizeof(float) << '.' << '\n';
    std::cout << "Size of double: " << "\t\t" << sizeof(double) << '.' << '\n';
    std::cout << "Size of long double: " << "\t" << sizeof(long double) << '.' << '\n';
    std::cout << "Size of enum E1: " << "\t\t" << sizeof(E1) << '.' << '\n';
    std::cout << "Size of enum E2: " << "\t\t" << sizeof(E2) << '.' << '\n';
    std::cout << "Size of string: " << "\t\t" << sizeof(std::string) << '.' << '\n';
    std::cout << "Size of char*: " << "\t\t\t" << sizeof(char*) << '.' << '\n';
    std::cout << "Size of bool*: " << "\t\t\t" << sizeof(bool*) << '.' << '\n';
    std::cout << "Size of long double*: " << "\t" << sizeof(long double*) << '.' << '\n';

    return 0;
}