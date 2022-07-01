#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> Vowels_word, con_words;

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

void separated_words(string str) {
    for (int i = 0; i < str.size(); i++) {
        string word = "";
        if (is_Vowel(str[i]) && is_Char(str[i])) {
            for (int j = i; j < str.size(); j++) {
                if (str[j] == ' ' || j == str.size() - 1) {
                    if (j == str.size() - 1) {
                        word += str[j];
                    }
                    i = j;
                    break;
                }
                word += str[j];
            }
            Vowels_word.push_back(word);
        } else if (!is_Vowel(str[i]) && is_Char(str[i])) {
            for (int j = i; j < str.size(); j++) {
                if (str[j] == ' ' || j == str.size() - 1) {
                    if (j == str.size() - 1) {
                        word += str[j];
                    }
                    i = j;
                    break;
                }
                word += str[j];
            }
            con_words.push_back(word);
        }
    }

    cout << "Vowels Words: " << endl;
    for (string word : Vowels_word) cout << word << " ";
    cout << endl;

    cout << "Consonants Words: " << endl;
    for (string word : con_words) cout << word << " ";
    cout << endl;

}

int main() {
    string str = "Munmun is the student of Computer Science & Engineering";
    cout << "String: " << str << endl;
    separated_words(str);
}