#include <iostream>


int main() {
    char c = 'r';
    char *p = &c;
    int a[10] = {1,2,3,4};
    int &pa = *a;
    std::string as[] = {"pzdc", "dcp"};
    std::string *pas = as;
    char **sym = &p;
    const int dcp = 228;
    const int *pdcp = &dcp;
    int pzdc = 228;
    int *const ipdcp = &pzdc;

    return 0;
}
