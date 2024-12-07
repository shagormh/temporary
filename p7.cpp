#include <iostream>
#include <sstream>
#include <cctype>
#include <set>
using namespace std;

void separateRelationalOperators(const string& statement) {
    string operators[] = {"==", "!=", "<=", ">=", "<", ">"};
    cout << "Relational Operators: ";

    for (const auto& op : operators) {
        size_t pos = statement.find(op);
        while (pos != string::npos) {
            cout << op << " ";
            pos = statement.find(op, pos + 1);
        }
    }
    cout << endl;
}


int main() {
    string statement = "if (a >= b && c < d)";
    separateRelationalOperators(statement);
    return 0;
}
