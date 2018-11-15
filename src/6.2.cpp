#include <iostream>

int f(int a, int b){
    return a+b;
}
int main() {
    int a, b = 1, c = -1, d = 3, x = 1, i = 228;
    int arr [5][5];
    int *pb = &b;
    int *pd = &d;

    a = ((b + (c * d)) << 2) & 8;
    std::cout << a << '\n';

    std::cout << ((a & 077) != 3) << '\n';
    std::cout << ( a == b ||(a == c && c < 5)) << '\n';
    std::cout << (c = (x!= 0)) << '\n';
    std::cout << ((0 <= i) < 99) << '\n';
    std::cout << ((0 <= i) < 99) << '\n';
    std::cout << (f(1,2)+3) << '\n';
//    a = -1++b--5;  // simple braces not working here
    a = (b == (c++));
    std::cout << a << '\n';
    a = (b = (c = 0));
    std::cout << a << '\n';
    arr[4][2] *= (*pb) ? c : ((*pd) * 2);
    std::cout << arr[4][2] << '\n';
    std::cout << ((a-b), (c=d)) << '\n';
    return 0;
}
