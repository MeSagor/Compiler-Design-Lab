#include<iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<pair<char, string>>Grammer;
string specialChars = { '@','#','&','^', '$' };

void StackAndInput(string stack, string input) {
    cout << "\n$";
    for (auto x : stack) cout << x;
    cout << "\t";
    for (auto x : input) cout << x;
    cout << "$";
}

bool is_integer(string token) {
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

pair<string, bool> Lexical_analyzer(string expression) {
    string tokenizeExp = "";
    string token = "";
    bool allOk = true;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '(' || expression[i] == ')' || i == expression.size() - 1) {
            if (i == expression.size() - 1 && (expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/' && expression[i] != '(' && expression[i] != ')'))
                token += expression[i];
            if (is_integer(token) and token != "") {
                tokenizeExp += "int";
            } else if (is_identifier(token) and token != "") {
                tokenizeExp += "ide";
            } else if (token != "") {
                allOk = false;
                break;
            }
            if (i < expression.size() - 1) tokenizeExp += expression[i];
            else if (i == expression.size() - 1 && (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '(' || expression[i] == ')')) {
                tokenizeExp += expression[i];
            }
            token = "";
        } else {
            token += expression[i];
        }
    }
    return { tokenizeExp, allOk };
}

void Validator(string input) {
    string stack;

    cout << "\nstack\t input\t action";
    for (int i = 0; i < input.size(); i++) {
        stack.push_back(input[i]);
        input[i] = ' ';
        StackAndInput(stack, input);

        int idx = 0;
        while (true) {
            idx++;
            int pos = stack.size() - idx;
            if (pos < 0) break;

            string now = stack.substr(pos);
            for (auto x : Grammer) {
                if (x.second == now) {
                    idx = 0;
                    cout << "\t " << "REDUCE " << x.first << "->" << now;
                    string rem = stack.substr(0, pos);
                    stack = rem;
                    stack.push_back(x.first);
                    StackAndInput(stack, input);
                }
            }
        }
    }
    cout << endl << endl << "VERDICT: ";
    if (stack.size() == 1 and stack[0] == 'E') cout << "VALID" << endl;
    else cout << "INVALID" << endl;
}


int main() {
    freopen("input.txt", "r", stdin);

    // Input style......

    // 8
    // E->E+E
    // E->E-E
    // E->E*E 
    // E->E/E
    // E->(E)
    // E->a
    // E->b
    // E->c
    // a+(b*c)

    // cout << "Enter Number of productions: ";
    int numofProductions;
    cin >> numofProductions;

    // cout << "Enter productions:" << endl;
    for (int i = 0; i < numofProductions; i++) {
        string s;
        cin >> s;
        Grammer.push_back({ s[0], s.substr(3) });
    }
    cout << "GRAMMAR:" << endl;
    for (auto x : Grammer) cout << x.first << "->" << x.second << endl;

    // cout << "Enter Input: ";
    string input;
    cin >> input;
    cout << endl << "INPUT: " << input << endl;
    auto verdict = Lexical_analyzer(input);
    if (verdict.second == false) {
        cout << "Wrong identifier or integer" << endl;
        cout << endl << endl << "VERDICT: ";
        cout << "INVALID" << endl;
        return 0;
    }
    input = verdict.first;
    cout << "Analyzed INPUT: " << input << endl;

    Validator(input);
}
