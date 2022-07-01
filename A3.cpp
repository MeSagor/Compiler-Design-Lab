#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, string> database;

void insert_in_database(string codeWord, string abbreviatedWord) {
    database[codeWord] = abbreviatedWord;
}

int main() {
    insert_in_database("CSE-3141", "Computer Science & Enginnering, 3rd year, 1st semester, Compiler Design, Theory");
    insert_in_database("CSE-3162", "Computer Science & Enginnering, 3rd year, 1st semester, Software Development Lab III, Lab");
    string codeword;
    cin >> codeword;
    cout << database[codeword] << endl;
}