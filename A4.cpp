#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool is_integerVariable(string expression) {
    bool flag = true;

    if ((expression[0] >= 'i' && expression[0] <= 'n') || ((expression[0] >= 'I' && expression[0] <= 'N'))) {
    } else {
        flag = false;
    }

    for (int i = 1; i < expression.size(); i++) {
        if ((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z') || (expression[i] >= '0' && expression[i] <= '9')) {
        } else {
            flag = false;
        }
    }
    return flag;
}

bool is_shortint(string expression) {
    bool flag = true;

    if (expression.size() > 4) {
        flag = false;
    } else {
        for (int i = 0; i < expression.size(); i++) {
            if (i == 0) {
                if (expression[i] >= '1' && expression[i] <= '9') {
                } else {
                    flag = false;
                }
            } else {
                if (expression[i] >= '0' && expression[i] <= '9') {
                } else {
                    flag = false;
                }
            }
        }
    }
    return flag;
}

bool is_longint(string expression) {
    bool flag = true;

    for (int i = 0; i < expression.size(); i++) {
        if (i == 0) {
            if (expression[i] >= '1' && expression[i] <= '9') {
            } else {
                flag = false;
            }
        } else {
            if (expression[i] >= '0' && expression[i] <= '9') {
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