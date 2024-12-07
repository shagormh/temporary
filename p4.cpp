#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Set of arithmetic operators in C++
const set<char> arithmeticOperators = {'+', '-', '*', '/', '%'};

int main() {
    string input;
    cout << "Enter a statement: ";
    getline(cin, input);

    vector<char> operators;
    string filteredInput;

    // Iterate through the input to identify operators
    for (char ch : input) {
        if (arithmeticOperators.find(ch) != arithmeticOperators.end()) {
            operators.push_back(ch); // If it's an operator, store it
        } else {
            filteredInput += ch; // Otherwise, add it to the non-operator string
        }
    }

    // Output the arithmetic operators
    cout << "Arithmetic Operators: ";
    for (char op : operators) {
        cout << op << " ";
    }
    cout << endl;

    // Output the rest of the statement
    cout << "Other Content: " << filteredInput << endl;

    return 0;
}
