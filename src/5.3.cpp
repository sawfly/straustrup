#include <iostream>

typedef unsigned char uc;
typedef const unsigned char cuc;
typedef int *pi;
typedef char **ppc;
//TODO is this can be a pointer on array of char?
typedef char* pac[];
typedef int *api[7];
typedef api *papi;
//TODO eight arrays api. I'm not shure that this is right type definition, also I can't initialize this
typedef api api8[8];

int main() {
    uc a = 'r';
    cuc b = 'b';
    int c = 3;
    pi d = &c;
    char e = 'e';
    char *f = &e;
    ppc g = &f;
    //pac
    char h[] = {'a', 'b', 'c'};
    pac i = {h};
    //pac
    int j[] = {0,1,2,3,4,5,6};
    api k = {&j[0],&j[1],&j[2],&j[3],&j[4],&j[5],&j[6]};
    papi l = &k;

    int m[] = {7,8,9,10,11,12,13};
    int n[] = {14,15,16,17,18,19,20};
    int o[] = {21,22,23,24,25,26,27};
    int p[] = {28,29,30,31,32,33,34};
    int q[] = {35,36,37,38,39,40,41};
    int r[] = {42,43,44,45,46,47,48};
    int s[] = {49,50,51,52,53,54,55};
    api t = {&m[0],&m[1],&m[2],&m[3],&m[4],&m[5],&m[6]};
    api u = {&n[0],&n[1],&n[2],&n[3],&n[4],&n[5],&n[6]};
    api v = {&o[0],&o[1],&o[2],&o[3],&o[4],&o[5],&o[6]};
    api w = {&p[0],&p[1],&p[2],&p[3],&p[4],&p[5],&p[6]};
    api x = {&q[0],&q[1],&q[2],&q[3],&q[4],&q[5],&q[6]};
    api y = {&r[0],&r[1],&r[2],&r[3],&r[4],&r[5],&r[6]};
    api z = {&s[0],&s[1],&s[2],&s[3],&s[4],&s[5],&s[6]};
//    api8 a8 = {k, t, u, v, w, x, y, z};

    std::cout << "uc a: " << a << '\n';
    std::cout << "cuc b: " << b << '\n';
    std::cout << "pi d: " << d << '\n';
    std::cout << "ppc g: " << g << '\n';
    std::cout << "pac i: " << i << " I'm not sure that this is right" << '\n';
    std::cout << "api k: [" << '\n';
    for (auto ki : k){
        std::cout << '\t' << ki << " pointer on " << *ki << ",\n";
    }
    std::cout << "]" << '\n';
    std::cout << "papi l: " << l << '\n';

    return 0;
}
