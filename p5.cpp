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
        if (isalpha(token[0]) || token[0] == '_') {
            identifiers.insert(token);
        }
    }

    cout << "Identifiers: ";
    for (const auto& id : identifiers)
        cout << id << " ";
    cout << endl;
}

int main() {
    string statement = "int x = a + b * c;";
    separateIdentifiers(statement);
    return 0;
}
