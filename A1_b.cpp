#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> Letters, Digits, Others;

bool is_Char(char ch) {
    if (ch >= 'A' && ch <= 'Z')
        return true;
    if (ch >= 'a' && ch <= 'z')
        return true;
    return false;
}

bool is_Digit(char ch) {
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}

void Separates(string str) {
    int letters = 0, digits = 0, other = 0;

    for (int i = 0; i < str.size(); i++) {
        if (is_Char(str[i])) {
            Letters.push_back(str[i]);
        }
        if (is_Digit(str[i])) {
            Digits.push_back(str[i]);
        }
        if (!is_Char(str[i]) && !is_Digit(str[i])) {
            Others.push_back(str[i]);
        }
    }

    cout << "Letters: " << endl;
    for (char ch : Letters)
        cout << ch << " ";
    cout << endl << endl;

    cout << "Digits: " << endl;
    for (char ch : Digits)
        cout << ch << " ";
    cout << endl << endl;

    cout << "Others: " << endl;
    for (char ch : Others)
        cout << ch << " ";
    cout << endl << endl;
}


int main() {
    string str = "Md. Tareq Zaman, Part-3,2011";
    cout << "String: " << str << endl;
    Separates(str);
}