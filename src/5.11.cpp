#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

void print(std::string words[], unsigned short size);
bool inArray(std::string words[], unsigned short size, std::string valueToFind);

int main() {
    const short SIZE = 100;
    std::string words[SIZE];
    const std::string STOP_WORD = "quit";
    unsigned short i = 0;

    for (; i < SIZE;) {
        std::string word;
        std::cin >> word;

        if (word == STOP_WORD) {
            break;
        }
        if (inArray(words, static_cast<unsigned short>(i + 1), word)) {
            print(words, static_cast<unsigned short>(i + 1));
            continue;
        }

        words[i] = word;
        print(words, ++i);
    }

    print(words, i);

    return 0;
}

void print(std::string words[], unsigned short size) {
    std::string copyWords[size];

    for (int i = 0; i<size; i++){
        copyWords[i] = words[i];
    }

    std::sort(copyWords, copyWords + size);

    for (int i = 0; i < size;) {
        std::cout << copyWords[i];

        if (++i == size) {
            std::cout << '\n';
        } else {
            std::cout << ", ";
        }
    }
}

bool inArray(std::string words[], unsigned short size, std::string valueToFind) {
    for (int i = 0; i < size; i++) {
        if (words[i] == valueToFind) {
            return true;
        }
    }

    return false;
}