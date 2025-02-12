#include <bits/stdc++.h>
using namespace std;

string removeComments(string& s) {
    string result;
    bool SingleCom = false;
    bool MultiCom = false;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        // Check for start of single-line comment
        if (!MultiCom && !SingleCom && i + 1 < n && s[i] == '/' && s[i + 1] == '/') {
            SingleCom = true;
            ++i;
        }
        // Check for start of multi-line comment
        else if (!SingleCom && !MultiCom && i + 1 < n && s[i] == '/' && s[i + 1] == '*') {
            MultiCom = true;
            ++i; 
        }
        // End of single-line comment
        else if (SingleCom && s[i] == '\n') {
            SingleCom = false;
            result += s[i]; 
        }
        // End of multi-line comment
        else if (MultiCom && i + 1 < n && s[i] == '*' && s[i + 1] == '/') {
            MultiCom = false;
            ++i; 
        }
        // Append non-comment characters
        else if (!SingleCom && !MultiCom) {
            result += s[i];
        }
    }

    return result;
}

int main() {
    string s;
    cout << "Enter the input string (end with Ctrl+D for multiline input):" << endl;

    // Read multiline input
    string line;
    while (getline(cin, line)) {
        s += line + '\n';
    }

    string result = removeComments(s);

    cout << "\nString without comments: " << endl;
    cout << result << endl;

    return 0;
}
