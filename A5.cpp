#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool is_floatVariable(string token) {
    bool flag = true;

    if ((token[0] >= 'a' && token[0] <= 'h') || (token[0] >= 'A' && token[0] <= 'H')
        || (token[0] >= 'o' && token[0] <= 'z') || (token[0] >= 'O' && token[0] <= 'Z')) {
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

bool is_floatNumber(string token) {
    bool flag = true;
    bool zeroFound = false, beforePriod = true, afterPriod = false, havePriod = false;

    int afterPriod_Digit = 0;

    for (int i = 0; i < token.size(); i++) {
        if (beforePriod) {
            if (i == 0 && token[i] == '0') {
                zeroFound = true;
            } else if (token[i] != '.' && zeroFound) {
                flag = false;
            } else if (i == 0) {
                if (token[i] >= '1' && token[i] <= '9') {
                } else {
                    flag = false;
                }
            } else if (i > 0) {
                if (token[i] == '.') {
                    afterPriod = true;
                    beforePriod = false;
                    if (i < token.size() - 1) {
                        havePriod = true;
                    }
                } else if (token[i] >= '0' && token[i] <= '9') {
                } else {
                    flag = false;
                }
            }
        } else if (afterPriod) {
            if (token[i] >= '0' && token[i] <= '9' && afterPriod_Digit < 2) {
                afterPriod_Digit++;
            } else {
                flag = false;
            }
        }
    }
    return flag && havePriod;
}

bool is_doubleNumber(string token) {
    bool flag = true;
    bool zeroFound = false, beforePriod = true, afterPriod = false, havePriod = false;

    int afterPriod_Digit = 0;

    for (int i = 0; i < token.size(); i++) {
        if (beforePriod) {
            if (i == 0 && token[i] == '0') {
                zeroFound = true;
            } else if (token[i] != '.' && zeroFound) {
                flag = false;
            } else if (i == 0) {
                if (token[i] >= '1' && token[i] <= '9') {
                } else {
                    flag = false;
                }
            } else if (i > 0) {
                if (token[i] == '.') {
                    afterPriod = true;
                    beforePriod = false;
                    if (i < token.size() - 1) {
                        havePriod = true;
                    }
                } else if (token[i] >= '0' && token[i] <= '9') {
                } else {
                    flag = false;
                }
            }
        } else if (afterPriod) {
            if (token[i] >= '0' && token[i] <= '9') {
                afterPriod_Digit++;
            } else {
                flag = false;
            }
        }
    }
    if (afterPriod_Digit < 3) flag = false;
    return flag && havePriod;
}

void Lexical_analyzer(string expression) {
    string token = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == ' ' || i == expression.size() - 1) {
            if (i == expression.size() - 1)
                token += expression[i];
            if (is_floatVariable(token)) {
                cout << "Float Variable: " << token << endl;
            } else if (is_floatNumber(token)) {
                cout << "Float Number: " << token << endl;
            } else if (is_doubleNumber(token)) {
                cout << "Double Number: " << token << endl;
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
    string expression = "a09 i90 0. 00.00 01.09 10.09 10.090";
    cout << "String: " << expression << endl;
    Lexical_analyzer(expression);
}