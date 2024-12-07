#include <bits/stdc++.h>
using namespace std;

int main() {
    // Set of delimiters
    set<char> delimiters = {',', ';', '\'', '{', '}', '|', '\\', '/','"'};

    // Input string
    string s = R"(#include <iostream> 
                using namespace std; 

                int main() {
                    // Output "Hello, World!" to the console
                    cout << "Hello, World!" << endl;

                    return 0; // Indicates successful program termination
                }
          )";

    string result;

    for (char c : s) {
        if (delimiters.find(c) == delimiters.end()) {
            result += c;
        }
    }

    cout << "\nString without delimiters: " << endl;
    cout << result << endl;

    return 0;
}
