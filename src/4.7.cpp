#include <iostream>

int main() {
    std::cout << "Graphs of main fundamentals types\n";

    std::cout << "      bool\n"
              << "  ------------\n"
              << "  |    |     |\n"
              << "char  int  double\n";


    std::cout << "      char\n"
              << "  ------------\n"
              << "  |    |     |\n"
              << "bool  int  double\n";


    std::cout << "      int\n"
              << "  -------------\n"
              << "  |    |      |\n"
              << "bool  char  double\n";


    std::cout << "     double\n"
              << "  ------------\n"
              << "  |    |     |\n"
              << "bool  char  int\n";

    return 0;
}