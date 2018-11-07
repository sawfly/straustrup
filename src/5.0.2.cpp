#include <iostream>
#include <cstring>

void g(const char *p, const char *q);

int main() {
    char v [] = "Annemarie" ;
    char* p = v; // неявное преобразование от char [] к char*

    std::cout << v << '\n';
    std::cout << p << '\n';
    std::cout << v[0] << '\n';
    std::cout << p[0] << '\n';
    std::cout << strlen (p) << '\n';
    std::cout << strlen (v) << '\n';

//    Errors
//    char* pp = "Annemarie"; // неявное преобразование от char [] к char*
//    char vv [9] = pp ;
}