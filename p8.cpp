#include <iostream>
#include <sstream>
#include <cctype>
#include <set>
using namespace std;

bool isCFG() {
    // Example: Grammar check logic for CFG.
    // Placeholder implementation
    return true; // Assume CFG for now
}

bool isRG() {
    // Example: Check if grammar is regular.
    // Placeholder implementation
    return false;
}

int main() {
    if (isCFG()) {
        cout << "Grammar belongs to CFG." << endl;
    } else if (isRG()) {
        cout << "Grammar belongs to RG." << endl;
    } else {
        cout << "Grammar belongs to CSG." << endl;
    }
    return 0;
}
