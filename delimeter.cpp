#include <bits/stdc++.h>

using namespace std;

int main() {
    // Open the file in read mode
    FILE *file = fopen("nmbr_of_even.cpp", "r");
    if (file == NULL) {
        cout << "Error opening file" << endl;
        return 1;
    }

    char ch;
    string delimiters[] = {",", ".", ";", "=", ":", "(", ")", "b", "->", "=>", "%"};
    set<string> delimiterSet(delimiters, delimiters + sizeof(delimiters) / sizeof(delimiters[0]));

    string buffer = "";
    char prev = '\0';

    cout << "Characters excluding delimiters:\n";

    // Read file character by character
    while ((ch = fgetc(file)) != EOF) {
        // Handle multi-character delimiters
        string multiChar = "";
        multiChar += prev;
        multiChar += ch;

        if (delimiterSet.count(string(1, ch))) {
            continue; // Skip single-character delimiters
        } else if (delimiterSet.count(multiChar)) {
            prev = '\0'; // Skip multi-character delimiter
            continue;
        } else {
            cout << ch; // Print non-delimiters
        }

        prev = ch; // Track the last character for multi-character check
    }

    fclose(file);
    return 0;
}
