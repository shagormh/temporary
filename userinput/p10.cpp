#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

// Simulate a DFA
bool simulateDFA(const string& input, int startState, const set<int>& acceptStates, const map<pair<int, char>, int>& transitions) {
    int state = startState;

    for (char ch : input) {
        auto transition = transitions.find({state, ch});
        if (transition == transitions.end()) {
            return false; // No valid transition
        }
        state = transition->second;
    }

    return acceptStates.find(state) != acceptStates.end(); // Check if in an accept state
}

int main() {
    // DFA definition
    int startState = 0;
    set<int> acceptStates = {2};
    map<pair<int, char>, int> transitions = {
        {{0, 'a'}, 1},
        {{1, 'b'}, 2}
    };

    // Input from user
    string input;
    cout << "Enter the input string: ";
    cin >> input;

    // Simulate DFA
    if (simulateDFA(input, startState, acceptStates, transitions)) {
        cout << "Accepted" << endl;
    } else {
        cout << "Rejected" << endl;
    }

    return 0;
}


/*
Example Input/Output::
Input:
Enter the input string: ab
Output:
Accepted

Input:
Enter the input string: aa
Output:
Rejected
*/