#include <iostream>
#include <stack>
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == ')') {
            bool found = false;

            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                st.pop();

                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    found = true;
                }
            }

            if (!found) {
                return true;
            }

            st.pop(); // Remove the opening '('
        } else {
            st.push(ch);
        }
    }

    return false;
}

int main() {
    // Example usage
    string expression = "((a+b))";
    
    if (findRedundantBrackets(expression)) {
        cout << "Redundant brackets found." << endl;
    } else {
        cout << "No redundant brackets found." << endl;
    }

    return 0;
}
