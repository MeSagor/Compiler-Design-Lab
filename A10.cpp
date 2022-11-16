#include<iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<pair<char, string>>Grammer;
string input, stack;
void StackAndInput() {
    cout << "\n$";
    for (auto x : stack) cout << x;
    cout << "\t";
    for (auto x : input) cout << x;
    cout << "$";
}

int main() {
    freopen("input.txt", "r", stdin);
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
    cin >> input;
    cout << endl << "INPUT: " << input << endl;

    cout << "\nstack\t input\t action";

    for (int i = 0; i < input.size(); i++) {
        stack.push_back(input[i]);
        input[i] = ' ';
        StackAndInput();

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
                    StackAndInput();
                }
            }
        }
    }
    cout << endl << endl << "VERDICT: ";
    if (stack.size() == 1 and stack[0] == 'E') cout << "Accepted" << endl;
    else cout << "Rejected" << endl;

}
