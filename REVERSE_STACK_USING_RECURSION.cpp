#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s, int element) {
    // Base case
    if (s.empty()) {
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    // Recursive call
    insertAtBottom(s, element);

    s.push(num);
}

void reverseStack(stack<int>& stack) {
    // Base case
    if (stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();

    // Recursive call
    reverseStack(stack);

    insertAtBottom(stack, num);
}

int main() {
    // Example usage
    stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Stack before reversal:" << endl;
    stack<int> tempStack = myStack;
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    reverseStack(myStack);

    cout << "Stack after reversal:" << endl;
    tempStack = myStack;
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    return 0;
}
