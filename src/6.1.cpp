#include <iostream>

int main() {
    char str [] = "Is this a test string??";
    char * str2 = str;
    int max_length = sizeof(str);
    int quest_count = 0;

    for(int i=0; i < max_length; i++){
        if (str[i] == '?') {
            quest_count++;
        }
    }
    std::cout << quest_count << '\n';

    quest_count = 0;
    int i=0;
    while (i++ < max_length){
        if (str[i] == '?') {
            quest_count++;
        }
    }
    std::cout << quest_count << '\n';

    quest_count = 0;
    while ('\0' != *str2){
        if (*str2++ == '?') {
            quest_count++;
        }
    }
    std::cout << quest_count << '\n';


    return 0;
}
