#include <iostream>


int main() {
    char c = 'r';
    char cc = 'r';
    char ccc = 'r';
    int i = 18;

    char *pc = &c;
    char *pcc = &cc;
    char *pccc = &ccc;
    int *pi = &i;
    void *pvoidi = &i;
    void *pvoidc = &c;

    std::cout << &pc << '\t' << &pcc << '\t' << &pccc << ";\n";
    std::cout << &pi << '\t' << &pvoidi << '\t' << &pvoidc << ";\n";

    return 0;
}
