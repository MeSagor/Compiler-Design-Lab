#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> nounSubject = { "Sagor", "Selim", "Salma", "Nipu" };
vector<string> pronounSubject = { "I", "He", "She", "We", "You", "They" };
vector<string> verbs = { "read", "eat", "take", "run", "write" };
vector<string> nounPredicte = { "book", "cow", "dog", "home", "grass", "rice", "mango" };

bool found_in_nouns_and_pronouns(string token) {
    for (string x : nounSubject) {
        if (x == token) return true;
    }
    for (string x : pronounSubject) {
        if (x == token) return true;
    }
    return false;
}

bool found_in_verbs(string token) {
    for (string x : verbs) {
        if (x == token) return true;
    }
    return false;
}

bool found_in_predictes(string token) {
    for (string x : nounPredicte) {
        if (x == token) return true;
    }
    return false;
}

void Lexical_analyzer(string expression) {
    string token = "";
    int next = 1;
    bool isValid = true;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == ' ' || i == expression.size() - 1) {
            if (i == expression.size() - 1)
                token += expression[i];
            if (next == 1 && !found_in_nouns_and_pronouns(token)) {
                isValid = false;
            }
            if (next == 2 && !found_in_verbs(token)) {
                isValid = false;
            }
            if (next == 3 && !found_in_predictes(token)) {
                isValid = false;
            }
            next++;
            token = "";
        } else {
            token += expression[i];
        }
    }
    if (isValid) cout << "Verdict: Syntactically Valid" << endl;
    else cout << "Verdict: Syntactically invalid" << endl;
}

int main() {
    string expression = "Sagor take rice";
    cout << "String: " << expression << endl;
    Lexical_analyzer(expression);
}