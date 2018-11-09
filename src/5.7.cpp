#include <iostream>

void print1();

void print2();

int main() {
    print2();
    std::cout << '\n';
    print1();
    std::cout << '\n';
    return 0;
}

void print2() {
    char jan[] = "Jan";
    char feb[] = "Feb";
    char mar[] = "Mar";
    char apr[] = "Apr";
    char may[] = "May";
    char jun[] = "Jun";
    char jul[] = "Jul";
    char aug[] = "Aug";
    char sep[] = "Sep";
    char oct[] = "Oct";
    char nov[] = "Nov";
    char dec[] = "Dec";
    char *months[] = {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (auto i : months) {
        std::cout << i << '\t';
    }
    std::cout << '\n';
    for (auto i : days) {
        std::cout << i << '\t';
    }
}

void print1() {
    struct Month {
        char shortName[4];
        int days;
    };
    Month months[] = {
            {"Jan", 31},
            {"Feb", 28},
            {"Mar", 31},
            {"Apr", 30},
            {"May", 31},
            {"Jun", 30},
            {"Jul", 31},
            {"Aug", 31},
            {"Sep", 30},
            {"Oct", 31},
            {"Nov", 30},
            {"Dec", 31}
    };

    for (auto i : months) {
        std::cout << i.shortName << '\t';
    }
    std::cout << '\n';
    for (auto i : months) {
        std::cout << i.days << '\t';
    }

}
