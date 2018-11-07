#include <iostream>

void g(const char *p, const char *q);

int main() {
    const char *p = "Heraclitus";
    const char *q = "Heraclitus";

    g(p, q);

    return 0;
}

void g(const char *p, const char *q) {
    if (p == q) {
        std::cout << "one\n";
    }  //результат зависит от конкретной реализации
};