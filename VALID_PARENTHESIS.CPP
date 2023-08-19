#include <iostream>
#include <stack>
using namespace std;

/* Function to check if the given string has valid brackets */
bool isValidParenthesis(string s) {
    stack<char> st;

    // Storing all opening brackets in the stack
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else {
            if (st.empty()) {
                return false;
            }

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                return false;
            }
        }
    }

    // If the stack is empty, all brackets are valid
    return st.empty();
}

int main() {
    // Example usage
    string input = "{[()]}";

    if (isValidParenthesis(input)) {
        cout << "Valid brackets" << endl;
    } else {
        cout << "Invalid brackets" << endl;
    }

    return 0;
}
