#include <iostream>

int main() {
    int a = 13;
    int b = 88;

    int *pa = &a;
    int *pb = &b;

    int *ptemp;

    std::cout << "a = " << a << "\t" << "b = " << b << "\t" << "pa = " << pa << "\t" << "*pa = " << *pa << "\t"  << "pb = " << pb << "\t" << "*pb = " << *pb << "\n";

    ptemp = pa;
    pa = pb;
    pb = ptemp;

    *pa *= 2;

    std::cout << "a = " << a << "\t" << "b = " << b << "\t" << "pa = " << pa << "\t" << "*pa = " << *pa << "\t"  << "pb = " << pb << "\t" << "*pb = " << *pb << "\n";

    return 0;
}