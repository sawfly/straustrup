#include <iostream>
#include <limits>

int main() {
    std::cout << "MIN and MAX values of some types:\n";

    std::cout << "char: [" << std::numeric_limits<char>::min() << ";" << std::numeric_limits<char>::max() << "]\n";
    std::cout << "charcode: [" << int(std::numeric_limits<char>::min()) << ";" << int(std::numeric_limits<char>::max())
              << "]\n";
    std::cout << "short: [" << std::numeric_limits<short>::min() << ";" << std::numeric_limits<short>::max() << "]\n";
    std::cout << "int: [" << std::numeric_limits<int>::min() << ";" << std::numeric_limits<int>::max() << "]\n";
    std::cout << "long: [" << std::numeric_limits<long>::min() << ";" << std::numeric_limits<long>::max() << "]\n";
    std::cout << "float: [" << std::numeric_limits<float>::min() << ";" << std::numeric_limits<float>::max() << "]\n";
    std::cout << "double: [" << std::numeric_limits<double>::min() << ";" << std::numeric_limits<double>::max()
              << "]\n";
    std::cout << "long double: [" << std::numeric_limits<long double>::min() << ";"
              << std::numeric_limits<long double>::max() << "]\n";
    std::cout << "unsigned: [" << std::numeric_limits<unsigned>::min() << ";" << std::numeric_limits<unsigned>::max()
              << "]\n";

    return 0;
}