#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


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

bool is_characterVariable(string token) {
    bool flag = true;

    if (token.size() < 4) {
        return false;
    }

    if (token[0] != 'c' || token[1] != 'h' && token[2] != '_') {
        return false;
    }

    for (int i = 3; i < token.size(); i++) {
        if (!is_Char(token[i]) && !is_Digit(token[i])) {
            return false;
        }
    }
    return flag;
}

bool is_binaryVariable(string token) {
    bool flag = true;

    if (token.size() < 4) {
        return false;
    }

    if (token[0] != 'b' || token[1] != 'n' && token[2] != '_') {
        return false;
    }

    for (int i = 3; i < token.size(); i++) {
        if (!is_Char(token[i]) && !is_Digit(token[i])) {
            return false;
        }
    }
    return flag;
}

bool is_binaryNumber(string token) {
    bool flag = true;

    if (token.size() < 2 || token[0] != '0' || (token[1] != '0' && token[1] != '1')) {
        return false;
    }

    for (int i = 2; i < token.size(); i++) {
        if (token[i] != '0' && token[i] != '1') {
            return false;
        }
    }
    return flag;
}

void Lexical_analyzer(string expression) {
    string token = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == ' ' || i == expression.size() - 1) {
            if (i == expression.size() - 1)
                token += expression[i];
            if (is_characterVariable(token)) {
                cout << "Character Variable: " << token << endl;
            } else if (is_binaryVariable(token)) {
                cout << "Binary Variable: " << token << endl;
            } else if (is_binaryNumber(token)) {
                cout << "Binary Number: " << token << endl;
            } else {
                cout << "Undefined : " << token << endl;
            }
            token = "";
        } else {
            token += expression[i];
        }
    }
}

int main() {
    string expression = "ch_az bn_, bn_a9 010";
    cout << "String: " << expression << endl;
    Lexical_analyzer(expression);
}