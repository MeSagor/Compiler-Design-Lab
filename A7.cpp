#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string keywords[] = { "auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while" };
string operators[] = { "++", "--", "~", "!", "+", "-", "*", "/", "%", "&", "<<", ">>", "<", ">", "<=", ">=", "==", "!=", "&", "|", "&&" };
string specialChars = { '@','#','&','^', '$' };

bool is_keyword(string token) {
    for (string x : keywords) {
        if (token == x) return true;
    }
    return false;
}

bool is_operator(string token) {
    for (string x : operators) {
        if (token == x) return true;
    }
    return false;
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

void Lexical_analyzer(string expression) {
    string token = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == ' ' || i == expression.size() - 1) {
            if (i == expression.size() - 1)
                token += expression[i];
            if (is_keyword(token)) {
                cout << "Keyword: " << token << endl;
            } else if (is_operator(token)) {
                cout << "Operator: " << token << endl;
            } else if (!is_keyword(token) && !is_operator(token) && is_identifier(token)) {
                cout << "Identifier: " << token << endl;
            } else {
                cout << "Constant : " << token << endl;
            }
            token = "";
        } else {
            token += expression[i];
        }
    }
}

int main() {
    string expression = "break continue ++ * is_identifier is_ident$fier 012abc";
    cout << "String: " << expression << endl;
    Lexical_analyzer(expression);
}