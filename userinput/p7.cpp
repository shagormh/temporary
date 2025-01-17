#include <iostream>
#include <vector>
#include <string>
using namespace std;

void separateRelationalOperators(const string& statement) {
    vector<string> operators = {"==", "!=", "<=", ">=", "<", ">"};
    cout << "Relational Operators: ";

    for (const auto& op : operators) {
        size_t pos = statement.find(op);
        while (pos != string::npos) {
            cout << op << " ";
            pos = statement.find(op, pos + op.size()); // Move to the next occurrence
        }
    }
    cout << endl;
}

int main() {
    string statement;
    cout << "Enter a statement: ";
    getline(cin, statement);

    separateRelationalOperators(statement);
    return 0;
}

/*
Example Usage
Input:
Enter a statement: if (a >= b && c < d || e == f)
Output:
Relational Operators: >= < == 
*/