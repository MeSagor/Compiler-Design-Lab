#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> Vowels_word, Con_words;

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

void Lexical_analyzer(string expression) {
    string token = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == ' ' || i == expression.size() - 1) {
            if (i == expression.size() - 1) {
                token += expression[i];
            }
            if (is_Vowel(token[0]) && is_Char(token[0])) {
                Vowels_word.push_back(token);
            } else if (!is_Vowel(token[0]) && is_Char(token[0])) {
                Con_words.push_back(token);
            }
            token = "";
        } else {
            token += expression[i];
        }
    }

    cout << "Vowels Words: ";
    for (string word : Vowels_word) cout << word << " ";
    cout << endl;

    cout << "Consonants Words: ";
    for (string word : Con_words) cout << word << " ";
    cout << endl;
}

int main() {
    string str = "Munmun is the student of Computer Science & Engineering";
    cout << "String: " << str << endl;
    // separated_words(str);
    Lexical_analyzer(str);
}