#include <iostream>
#include <time.h>

int main() {
    struct Link
    {
        Link* previous;
        int id;
    };

    Link a;
    a.id = 1;
    Link b;
    b.id=2;
    b.previous = &a;

    std::cout << (*b.previous).id << '\n';
    return 0;
}