#include <iostream>

void f(char);

void g(char &);

void h(const char &);

int main() {
    f('a');
//    g('a');
    h('a'); //temp

    f(49);
//    g(49);
    h(49); //temp

    f(3300); //warning: overflow in implicit constant conversion [-Woverflow]
//    g(3300);
    h(3300);//warning: overflow in implicit constant conversion [-Woverflow]

    char c = 'c';
    unsigned char uc = 'u';
    signed char sc = 's';
    f(c);
    g(c);
    h(c); //temp
    f(uc);
//    g(uc);
    h(uc); //temp
    f(sc);
//    g(sc);
    h(sc); //temp

    return 0;
}

void f(char ch) {
    std::cout << ch << '\n';
}

void g(char &ch) {
    std::cout << ch << '\n';
}

void h(const char &ch) {
    std::cout << ch << '\n';
}