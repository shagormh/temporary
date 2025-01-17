#include <iostream>
#include <vector>
#include <string>
#include <regex>
using namespace std;

// Function to check if a production rule belongs to Regular Grammar
bool isRG(const vector<string>& productions) {
    regex rgLeft("^[A-Z]->[a-z]*[A-Z]?$"); // A -> aB or A -> a
    regex rgRight("^[A-Z]->[A-Z]?[a-z]*$"); // A -> Ba or A -> a

    for (const string& rule : productions) {
        if (!regex_match(rule, rgLeft) && !regex_match(rule, rgRight)) {
            return false;
        }
    }
    return true;
}

// Function to check if a grammar is Context-Free Grammar
bool isCFG(const vector<string>& productions) {
    regex cfg("^[A-Z]->.*$"); // A -> α (α can be any string of terminals/non-terminals)

    for (const string& rule : productions) {
        if (!regex_match(rule, cfg)) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<string> productions;
    int n;

    // Input production rules
    cout << "Enter the number of production rules: ";
    cin >> n;
    cin.ignore(); // Ignore the newline character after the number

    cout << "Enter the production rules (e.g., A->aB):" << endl;
    for (int i = 0; i < n; ++i) {
        string rule;
        getline(cin, rule);
        productions.push_back(rule);
    }

    // Determine grammar type
    if (isRG(productions)) {
        cout << "Grammar belongs to Regular Grammar (RG)." << endl;
    } else if (isCFG(productions)) {
        cout << "Grammar belongs to Context-Free Grammar (CFG)." << endl;
    } else {
        cout << "Grammar belongs to Context-Sensitive Grammar (CSG)." << endl;
    }

    return 0;
}

/*
Example Input/Output

Input:

Enter the number of production rules: 3
Enter the production rules (e.g., A->aB):
S->aA
A->bB
B->c

Output:

Grammar belongs to Regular Grammar (RG).
*/