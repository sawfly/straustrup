#include <iostream>

int main() {
    char str[] = "a short string";
    std::string str2 = "a short string";

    std::cout << "Size of char str[] = \"a short string\": \t\t\t" << sizeof(str) << "\n";
    std::cout << "Length of std::string str2 = \"a short string\": \t" << str2.length() << "\n";

    return 0;
}