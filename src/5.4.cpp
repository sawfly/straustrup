#include <iostream>

void swap(int *, int *);
void swap(int &, int &);

int main() {
    int a = 1;
    int b = 2;

    std::cout << a << " (a) and " << b << " (b)\n";
    std::cout << "swap(&a, &b)\n";
    swap(&a, &b);
    std::cout << a << " (a) and " << b << " (b)\n";
    std::cout << "swap(a, b)\n";
    swap(a, b);
    std::cout << a << " (a) and " << b << " (b)\n";

    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}