#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& s, int x) {
    // Base case
    if (s.empty()) {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    // Recursive call
    solve(s, x);

    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) {
    solve(myStack, x);
    return myStack;
}

int main() {
    // Example usage
    stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Stack before insertion at bottom:" << endl;
    stack<int> tempStack = myStack;
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    pushAtBottom(myStack, 4);

    cout << "Stack after insertion at bottom:" << endl;
    tempStack = myStack;
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    return 0;
}
