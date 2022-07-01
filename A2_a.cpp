#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool is_Char(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        return true;
    if (ch >= 'a' && ch <= 'z')
        return true;
    return false;
}

bool is_Vowel(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
        return true;
    }
    return false;
}

void count_vowels_consonants(string str) {
    int vowels = 0, consonants = 0;

    for (int i = 0; i < str.size(); i++) {
        if (is_Vowel(str[i])) {
            vowels++;
        }

        if (!is_Vowel(str[i]) && is_Char(str[i])) {
            consonants++;
        }
    }

    cout << "Numbers of Vowels: " << vowels << endl;
    cout << "Numbers of Consonants: " << consonants << endl;
}


int main() {
    string str2 = "Munmun is the student of Computer Science & Engineering";
    cout << "String: " << str2 << endl;
    count_vowels_consonants(str2);
}