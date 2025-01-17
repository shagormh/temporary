#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;

void separateNumbers(const string& statement) {
    istringstream iss(statement);
    string token;

    cout << "Numbers: ";
    while (iss >> token) {
        // Remove trailing punctuation
        while (!token.empty() && ispunct(token.back()) && token.back() != '.') {
            token.pop_back();
        }

        // Check if it's a valid number
        if (!token.empty() && (isdigit(token[0]) || token[0] == '-' || token[0] == '+')) {
            cout << token << " ";
        }
    }
    cout << endl;
}

int main() {
    string statement;
    cout << "Enter a statement: ";
    getline(cin, statement);

    separateNumbers(statement);
    return 0;
}


/*
Input:

Enter a statement: x = 42 + 3.14 -7 +123.456e-1;

Output:

Numbers: 42 3.14 -7 

*/