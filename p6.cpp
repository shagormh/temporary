#include <iostream>
#include <sstream>
#include <cctype>
#include <set>
using namespace std;

void separateNumbers(const string& statement) {
    istringstream iss(statement);
    string token;

    cout << "Numbers: ";
    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            cout << token << " ";
        }
    }
    cout << endl;
}

int main() {
    string statement = "x = 42 + 3.14 - 7;";
    separateNumbers(statement);
    return 0;
}
