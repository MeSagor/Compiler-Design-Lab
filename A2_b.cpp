#include <iostream>
#include <string>
#include <vector>
#include<set>
using namespace std;

set<char> Vowels, Consonants;

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

void find_vowels_consonants(string str) {

    for (int i = 0; i < str.size(); i++) {
        if (is_Vowel(str[i])) {
            Vowels.insert(str[i]);
        }

        if (!is_Vowel(str[i]) && is_Char(str[i])) {
            Consonants.insert(str[i]);
        }
    }

    cout << "Vowels: " << endl;
    for (char ch : Vowels)
        cout << ch << " ";
    cout << endl;
    cout << "Consonants: " << endl;
    for (char ch : Consonants)
        cout << ch << " ";
    cout << endl;
}


int main() {
    string str2 = "Munmun is the student of Computer Science & Engineering";
    cout << "String: " << str2 << endl;
    find_vowels_consonants(str2);
}