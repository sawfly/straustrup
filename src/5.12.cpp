#include <iostream>
#include <cstring>
//#include <algorithm>
//#include <iterator>
//#include <string>

void countPairs(std::string &str);
void countPairsC(char* str);

bool inArray(std::string words[], unsigned long size, const std::string &valueToFind);

int main() {
    std::string defaultString = "default string for running script";
    std::string str;
    char *cString;
    std::string defaultAnswer = "y";
    std::string answer = "y";

    std::cout << "the default string is: \n\"" << defaultString << "\"\n" << "Do you want to use it? (y/n):";
    std::getline(std::cin, answer);

    if (answer == "n") {
        std::cout << "Enter string you want (2-1024 symbols):\n";
        std::getline(std::cin, str);
    } else {
        str = defaultString;
    }

    if (str.length() < 2) {
        std::cout << "String must be at least 2 symbols in length. Will use default string";
        str = defaultString;
    }

    cString = const_cast<char *>(str.c_str());

    std::cout << '\n';
    countPairs(str);
    std::cout << '\n';
    countPairsC(cString);

    return 0;
}

void countPairs(std::string &str) {
    std::cout << str << ":\n";
    unsigned long l = str.length();
    unsigned long appears = 0;
    unsigned long maxPairs = l - 1;
    std::string pairs[maxPairs];

    for (unsigned long i = 0, j = 1, m = 0; j < l; i++, j++) {
        std::string pair = str.substr(i, 2);

        if (!inArray(pairs, m, pair)) {
            pairs[m++] = pair;
        } else {
            continue;
        }

        appears = 1;

        for (auto k = j + 1; k < l - 1; k++) {
            std::string nextPair = str.substr(k, 2);
            if (pair == nextPair) {
                appears++;
            }
        }

        std::cout << "Pair of symbols \""
                  << pair
                  << "\" appears: \t\t"
                  << appears
                  << " time"
                  << (appears > 1 ? "s\n" : "\n");
    }
}

void countPairsC(char* str) {
    std::cout << str << ":\n";
    unsigned long l = strlen(str);
    unsigned long appears = 0;
    unsigned long maxPairs = l - 1;
    std::string pairs[maxPairs];

    for (unsigned long i = 0, j = 1, m = 0; j < l; i++, j++) {
        const char aPair[3] = {str[i], str[j]};
        const char * pair = aPair;

        if (!inArray(pairs, m, pair)) {
            pairs[m++] = aPair;
        } else {
            continue;
        }

        appears = 1;

        for (auto k = j + 1; k < l - 1; k++) {
            const char aNextPair[3] = {str[k], str[k+1]};
            const char * nextPair = aNextPair;
            if (pair[0] == nextPair[0] && pair[1] == nextPair[1]) {
                appears++;
            }
        }

        std::cout << "Pair of symbols \""
                  << pair
                  << "\" appears: \t\t"
                  << appears
                  << " time"
                  << (appears > 1 ? "s\n" : "\n");
    }
}



bool inArray(std::string words[], unsigned long size, const std::string &valueToFind) {
    for (int i = 0; i < size; i++) {
        if (words[i] == valueToFind) {
            return true;
        }
    }

    return false;
}