#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// Function to perform leftmost derivation
void leftmostDerivation(const map<string, vector<string>>& grammar, const string& startSymbol) {
    string current = startSymbol;
    cout << "Leftmost Derivation:\n" << current << endl;

    bool derived = true;
    while (derived) {
        derived = false;
        for (size_t i = 0; i < current.size(); ++i) {
            string symbol(1, current[i]);
            if (grammar.find(symbol) != grammar.end()) { // If it's a non-terminal
                string replacement = grammar.at(symbol)[0]; // Use the first production
                current.replace(i, 1, replacement);
                cout << "-> " << current << endl;
                derived = true;
                break; // Only replace the leftmost non-terminal
            }
        }
    }
}

int main() {
    map<string, vector<string>> grammar;
    int n;
    string startSymbol;

    // Input grammar rules
    cout << "Enter the number of production rules: ";
    cin >> n;
    cin.ignore();

    cout << "Enter the production rules (e.g., S->AB):\n";
    for (int i = 0; i < n; ++i) {
        string rule;
        getline(cin, rule);

        size_t arrowPos = rule.find("->");
        string left = rule.substr(0, arrowPos);
        string right = rule.substr(arrowPos + 2);

        grammar[left].push_back(right);
    }

    // Input start symbol
    cout << "Enter the start symbol: ";
    cin >> startSymbol;

    // Perform leftmost derivation
    leftmostDerivation(grammar, startSymbol);

    return 0;
}


/*

Example Input/Output

Input:

Enter the number of production rules: 3
Enter the production rules (e.g., S->AB):
S->AB
A->a
B->b
Enter the start symbol: S

Output:

plaintext
Copy
Edit
Leftmost Derivation:
S
-> AB
-> aB
-> ab
*/