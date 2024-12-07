#include <iostream>
#include <string>
using namespace std;

bool simulateDFA(const string& input) {
    int state = 0;

    for (char ch : input) {
        if (state == 0 && ch == 'a') state = 1;
        else if (state == 1 && ch == 'b') state = 2;
        else return false;
    }
    return state == 2;
}

int main() {
    string input = "ab";
    cout << (simulateDFA(input) ? "Accepted" : "Rejected") << endl;
    return 0;
}
