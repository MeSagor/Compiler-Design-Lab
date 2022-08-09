#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool is_integerVariable(string token) {
    bool flag = true;

    if ((token[0] >= 'i' && token[0] <= 'n') || ((token[0] >= 'I' && token[0] <= 'N'))) {
    } else {
        flag = false;
    }

    for (int i = 1; i < token.size(); i++) {
        if ((token[i] >= 'a' && token[i] <= 'z') || (token[i] >= 'A' && token[i] <= 'Z') || (token[i] >= '0' && token[i] <= '9')) {
        } else {
            flag = false;
        }
    }
    return flag;
}

bool is_shortint(string token) {
    bool flag = true;

    if (token.size() > 4) {
        flag = false;
    } else {
        for (int i = 0; i < token.size(); i++) {
            if (i == 0) {
                if (token[i] >= '1' && token[i] <= '9') {
                } else {
                    flag = false;
                }
            } else {
                if (token[i] >= '0' && token[i] <= '9') {
                } else {
                    flag = false;
                }
            }
        }
    }
    return flag;
}

bool is_longint(string token) {
    bool flag = true;

    for (int i = 0; i < token.size(); i++) {
        if (i == 0) {
            if (token[i] >= '1' && token[i] <= '9') {
            } else {
                flag = false;
            }
        } else {
            if (token[i] >= '0' && token[i] <= '9') {
            } else {
                flag = false;
            }
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
            if (is_integerVariable(token)) {
                cout << "Integer Variable: " << token << endl;
            } else if (is_shortint(token)) {
                cout << "ShortInt Number: " << token << endl;
            } else if (is_longint(token)) {
                cout << "LongInt Number: " << token << endl;
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
    string expression = "ijo, 1234 123450 ijkn 0123";
    cout << "String: " << expression << endl;
    Lexical_analyzer(expression);
}