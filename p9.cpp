#include <iostream>
#include <sstream>
#include <cctype>
#include <set>
using namespace std;

void leftmostDerivation() {
    cout << "S -> AB\nA -> a\nB -> b\n";
    cout << "Leftmost Derivation: S -> AB -> aB -> ab\n";
}

int main() {
    leftmostDerivation();
    return 0;
}
