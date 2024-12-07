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
        
        else if (!SingleCom && !MultiCom && i + 1 < n && s[i] == '/' && s[i + 1] == '*') {
            MultiCom = true;
            ++i; 
        }
        
        else if (SingleCom && s[i] == '\n') {
            SingleCom = false;
            result += s[i]; 
        }
        
        else if (MultiCom && i + 1 < n && s[i] == '*' && s[i + 1] == '/') {
            MultiCom = false;
            ++i; 
        }
        
        else if (!SingleCom && !MultiCom) {
            result += s[i];
        }
    }

    return result;
}

int main() {
    string s = R"(#include <iostream> 
                using namespace std; 

                int main() {
                    // Output "Hello, World!" to the console
                    cout << "Hello, World!" << endl;

                    return 0; /* Indicates successful program termination */
                }
          )";

    string result = removeComments(s);

    cout << "\nString without comments: " << endl;
    cout << result << endl;

    return 0;
}
