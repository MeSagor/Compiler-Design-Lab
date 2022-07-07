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

bool is_characterVariable(string expression) {
    bool flag = true;

    if (expression.size() < 4) {
        return false;
    }

    if (expression[0] != 'c' || expression[1] != 'h' && expression[2] != '_') {
        return false;
    }

    for (int i = 3; i < expression.size(); i++) {
        if (!is_Char(expression[i]) && !is_Digit(expression[i])) {
            return false;
        }
    }
    return flag;
}

bool is_binaryVariable(string expression) {
    bool flag = true;

    if (expression.size() < 4) {
        return false;
    }

    if (expression[0] != 'b' || expression[1] != 'n' && expression[2] != '_') {
        return false;
    }

    for (int i = 3; i < expression.size(); i++) {
        if (!is_Char(expression[i]) && !is_Digit(expression[i])) {
            return false;
        }
    }
    return flag;
}

bool is_binaryNumber(string expression) {
    bool flag = true;

    if (expression.size() < 2 || expression[0] != '0' || (expression[1] != '0' && expression[1] != '1')) {
        return false;
    }

    for (int i = 2; i < expression.size(); i++) {
        if (expression[i] != '0' && expression[i] != '1') {
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