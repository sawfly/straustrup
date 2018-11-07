#include <iostream>

int main() {
    char first[] = {
            'a',
            'b',
            'c',
            'd',
            'e',
            'f',
            'g',
            'h',
            'i',
            'j',
            'k',
            'l',
            'm',
            'n',
            'o',
            'p',
            'q',
            'r',
            's',
            't',
            'u',
            'v',
            'w',
            'x',
            'y',
            'z',
            '0',
            '1',
            '2',
            '3',
            '4',
            '5',
            '6',
            '7',
            '8',
            '9',
    };
    char others[] = {
            'A',
            'B',
            'C',
            'D',
            'E',
            'F',
            'G',
            'H',
            'I',
            'J',
            'K',
            'L',
            'M',
            'N',
            'O',
            'P',
            'Q',
            'R',
            'S',
            'T',
            'U',
            'V',
            'W',
            'X',
            'Y',
            'Z',
            '`',
            '~',
            '!',
            '@',
            '#',
            '$',
            '%',
            '^',
            '&',
            '*',
            '(',
            ')',
            '-',
            '_',
            '=',
            '+',
            '/',
            '?',
            '.',
            ',',
            '>',
            '<',
            '"',
            '\'',
            ';',
            ':',
            '\\',
            '|',
            '[',
            ']',
            '{',
            '}',
            ' ',
    };

    std::string cyrillic[] = {
            "а",
            "б",
            "в",
            "г",
            "ґ",
            "д",
            "е",
            "є",
            "ж",
            "з",
            "и",
            "і",
            "ї",
            "й",
            "к",
            "л",
            "м",
            "н",
            "о",
            "п",
            "р",
            "с",
            "т",
            "у",
            "ф",
            "х",
            "ц",
            "ч",
            "ш",
            "щ",
            "ь",
            "ю",
            "я",
            "ъ",
            "ы",
            "э",
            "А",
            "Б",
            "В",
            "Г",
            "Ґ",
            "Д",
            "Е",
            "Є",
            "Ж",
            "З",
            "И",
            "І",
            "Ї",
            "Й",
            "К",
            "Л",
            "М",
            "Н",
            "О",
            "П",
            "Р",
            "С",
            "Т",
            "У",
            "Ф",
            "Х",
            "Ц",
            "Ч",
            "Ш",
            "Щ",
            "Ь",
            "Ю",
            "Я",
            "Ъ",
            "Ы",
            "Э",
            "№",
    };
    for (auto &i : first){
        std::cout << "symbol \"" << i << "\" has code \"" << int(i) << "\";" << '\n';
    }

    for (auto &i : others){
        std::cout << "symbol \"" << i << "\" has code \"" << int(i) << "\";" << '\n';
    }

    for (auto &i : cyrillic){
        const char* symbol = i.c_str();
        std::cout << "symbol \"" << i << "\" has code \"" << symbol[0]+symbol[1] << "\";" << '\n';
    }
    return 0;
}