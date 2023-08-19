#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string str) {
    // Odd condition
    if (str.length() % 2 == 1) {
        return -1;
    }
    
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        
        if (ch == '{') 
            s.push(ch);
        else {
            // ch is a closed brace
            if (!s.empty() && s.top() == '{') {
                s.pop();
            } else {
                s.push(ch);
            }
        }
    }
    
    // Stack contains invalid expression
    int a = 0, b = 0;
    while (!s.empty()) {
        if (s.top() == '{') {
            b++;
        } else {
            a++;
        }
        s.pop();
    }
        
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main() {
    // Example usage
    string input = "}{{}}{{{";
    int result = findMinimumCost(input);
    cout << "Minimum cost to make the string valid: " << result << endl;

    return 0;
}
