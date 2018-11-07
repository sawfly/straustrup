#include <iostream>
#include <string>
#include <math.h>

struct Date {
    int d, m, y;
};

int day(Date *p);

//template<class T>
//T abs(T a) { return a < 0 ? -a : a; }

namespace NS { int a; }
//abs defined in math.h
template<class T> T abs(T a) {return a<0 ? -a : a; }

//TODO resolve
//typedef complex <short> Point;
double sqrt(double f);

int main() {
    char ch = 's';
    std::string s = "Holla";
    int count;
    const double pi = 3.1415926535897932385;
    /*extern can be initialized in other file `4_2_extern.cpp` */
    extern int error_number;
    const char *name;
    const char *season[4];
    struct User {
        std::string name = "BAJIEPA";
    };

    User uu;

    enum Beer {
        Carlsberg, Tuborg, Thor
    };

    Date testDate;
    testDate.d = 13;
    testDate.m = 7;
    testDate.y = 2020;
    Date *p = &testDate;
    std::cout << day(p) << '\n';

    std::cout << ch << "\n";

    std::cout << s << "\n";

    count = 1;
    std::cout << count << "\n";

    std::cout << pi << " const cann't be initialized in other place\n";

    std::cout << error_number << '\n';

    name = "Njal";
    std::cout << name << "\n";

    season[0] = "spring";
    season[1] = "summer";
    season[2] = "fall";
    season[3] = "winter";
    for (auto &i : season) {
        std::cout << i << "\n";
    }

    //here uses standard function from math.h. If we exclude #include <math.h> it will use defined by us function
    std::cout << sqrt(9) << "\n";

    std::cout << uu.name << "\n";

    std::cout << "enum cannot be initialized in other place" << "\n";
    std::cout << Beer::Carlsberg << Beer::Thor << Beer::Tuborg << "\n";

    std::cout << abs(-18) << '\n';

    return 0;
}

int day(Date *p) {
    return p->d;
}

double sqrt(double f) {
    return f*f;
}