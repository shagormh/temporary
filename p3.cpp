#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Set of C++ reserved keywords
const set<string> cppKeywords = {
    "asm", "auto", "break", "case", "catch", "char", "class", "const", "continue", 
    "default", "delete", "do", "double", "else", "enum", "extern", "float", "for", 
    "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", 
    "new", "operator", "private", "protected", "public", "register", "return", 
    "short", "signed", "sizeof", "static", "struct", "switch", "template", 
    "this", "throw", "try", "typedef", "union", "unsigned", "virtual", "void", 
    "volatile", "while"
};

// Function to check if a word is a C++ keyword
bool isCppKeyword(const string& word) {
    return cppKeywords.find(word) != cppKeywords.end();
}

int main() {
    string input;
    cout << "Enter a statement: ";
    getline(cin, input);

    // Convert to lowercase for uniformity
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    // Tokenize the input string
    stringstream ss(input);
    string word;
    vector<string> keywords;
    vector<string> nonKeywords;

    while (ss >> word) {
        // Remove punctuation from the word
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

        // Check if the word is a C++ keyword
        if (isCppKeyword(word)) {
            keywords.push_back(word);
        } else {
            nonKeywords.push_back(word);
        }
    }

    // Output the keywords
    cout << "C++ Keywords: ";
    for (const string& keyword : keywords) {
        cout << keyword << " ";
    }
    cout << endl;

    // Output the non-keywords
    cout << "Other Words: ";
    for (const string& nonKeyword : nonKeywords) {
        cout << nonKeyword << " ";
    }
    cout << endl;

    return 0;
}
