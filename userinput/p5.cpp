#include <iostream>
#include <sstream>
#include <cctype>
#include <set>
using namespace std;

void separateIdentifiers(const string& statement) {
    istringstream iss(statement);
    string token;
    set<string> identifiers;

    while (iss >> token) {
        // Remove trailing punctuation (like ;, =, etc.)
        while (!token.empty() && ispunct(token.back())) {
            token.pop_back();
        }

        // Check if it's a valid identifier (starts with a letter or _)
        if (!token.empty() && (isalpha(token[0]) || token[0] == '_')) {
            identifiers.insert(token);
        }
    }

    cout << "Identifiers: ";
    for (const auto& id : identifiers)
        cout << id << " ";
    cout << endl;
}

int main() {
    string statement;
    cout << "Enter a statement: ";
    getline(cin, statement);

    separateIdentifiers(statement);
    return 0;
}
