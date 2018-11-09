#include <iostream>
#include <time.h>

void walk1(int [], int);
void walk2(int [], int);

int main() {
    clock_t tStart = clock();
    int size = 1000000;
    int kk[size];

    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        kk[i] = rand();
    }

    walk1(kk, size);
    std::cout << '\n';
//    walk2(kk, size);
//    std::cout << '\n';
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


void walk1(int a[], int s){
    for (int i = 0; i < s ; i++){
        std::cout << a[i] << '\t';
    }
}

void walk2(int a[], int s){
    int *p = &a[0];
    for (int i = 0; i < s ; i++, p++){
        std::cout << *p << '\t';
    }
}