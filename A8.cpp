#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string keywords[] = { "auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while" };
string operators[4][10] = { {"+","-","*","/","%","++","--"},
                            {"==","!=",">","<",">=","<="},
                            {"&&","||","!"},
                            {"&","|","^","~","<<",">>"} };

string specialChars = { '@','#','&','^', '$' };


bool is_keyword(string token) {
    for (string x : keywords) {
        if (token == x) return true;
    }
    return false;
}

int is_operator(string token) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            if (token == operators[i][j]) {
                return i + 1;
            }
        }
    }
    return 0;
}

bool is_identifier(string token) {
    if (token[0] == '_' || (token[0] >= 'a' && token[0] <= 'z') || (token[0] >= 'A' && token[0] <= 'B')) {
        for (char tok : token) {
            for (char spe : specialChars) {
                if (tok == spe) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

bool is_constant(string token) {
    int priod = 0;
    for (char c : token) {
        if (c == '.') priod++;
        if ((c >= '0' && c <= '9') || ((c == '.') && (priod < 2))) continue;
        else return false;
    }
    return true;
}

bool is_floatNumber(string expression) {
    bool flag = true;
    bool zeroFound = false, beforePriod = true, afterPriod = false, havePriod = false;

    int afterPriod_Digit = 0;

    for (int i = 0; i < expression.size(); i++) {
        if (beforePriod) {
            if (i == 0 && expression[i] == '0') {
                zeroFound = true;
            } else if (expression[i] != '.' && zeroFound) {
                flag = false;
            } else if (i == 0) {
                if (expression[i] >= '1' && expression[i] <= '9') {
                } else {
                    flag = false;
                }
            } else if (i > 0) {
                if (expression[i] == '.') {
                    afterPriod = true;
                    beforePriod = false;
                    if (i < expression.size() - 1) {
                        havePriod = true;
                    }
                } else if (expression[i] >= '0' && expression[i] <= '9') {
                } else {
                    flag = false;
                }
            }
        } else if (afterPriod) {
            if (expression[i] >= '0' && expression[i] <= '9' && afterPriod_Digit < 2) {
                afterPriod_Digit++;
            } else {
                flag = false;
            }
        }
    }
    return flag && havePriod;
}

bool is_int(string expression) {
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

bool is_doubleNumber(string expression) {
    bool flag = true;
    bool zeroFound = false, beforePriod = true, afterPriod = false, havePriod = false;

    int afterPriod_Digit = 0;

    for (int i = 0; i < expression.size(); i++) {
        if (beforePriod) {
            if (i == 0 && expression[i] == '0') {
                zeroFound = true;
            } else if (expression[i] != '.' && zeroFound) {
                flag = false;
            } else if (i == 0) {
                if (expression[i] >= '1' && expression[i] <= '9') {
                } else {
                    flag = false;
                }
            } else if (i > 0) {
                if (expression[i] == '.') {
                    afterPriod = true;
                    beforePriod = false;
                    if (i < expression.size() - 1) {
                        havePriod = true;
                    }
                } else if (expression[i] >= '0' && expression[i] <= '9') {
                } else {
                    flag = false;
                }
            }
        } else if (afterPriod) {
            if (expression[i] >= '0' && expression[i] <= '9') {
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
            if (is_keyword(token)) {
                cout << "Keyword: " << token << endl;
            } else if (int code = is_operator(token)) {
                if (code == 1) cout << "Arithmetic Operators: " << token << endl;
                else if (code == 2) cout << "Relational Operators: " << token << endl;
                else if (code == 3) cout << "Logical Operators: " << token << endl;
                else if (code == 4) cout << "Bitwise Operators: " << token << endl;
            } else if (!is_keyword(token) && !is_operator(token) && is_identifier(token)) {
                cout << "Identifier: " << token << endl;
            } else if (is_constant(token)) {
                if (is_int(token)) {
                    cout << "Integer: " << token << endl;
                } else if (is_floatNumber(token)) {
                    cout << "Float: " << token << endl;
                } else if (is_doubleNumber(token)) {
                    cout << "Double: " << token << endl;
                }
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
    string expression = "break continue ++ * & && == is_identifier is_ident&fier 012abc 123 12.34 12.2345";
    cout << "String: " << expression << endl;
    Lexical_analyzer(expression);
}