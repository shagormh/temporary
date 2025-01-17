#include <bits/stdc++.h>
using namespace std;

int main() {
    // Set of delimiters
    set<char> delimiters = {',', ';', '\'', '{', '}', '|', '\\', '/', '"'};

    // Input string
    string s;
    cout << "Enter the input string (end with Ctrl+D for multiline input):" << endl;

    // Read multiline input
    string line;
    while (getline(cin, line)) {
        s += line + '\n';
    }

    string result;

    for (char c : s) {
        if (delimiters.find(c) == delimiters.end()) {
            result += c;
        }
    }

    cout << "\nString without delimiters: " << endl;
    cout << result << endl;

    return 0;
}
