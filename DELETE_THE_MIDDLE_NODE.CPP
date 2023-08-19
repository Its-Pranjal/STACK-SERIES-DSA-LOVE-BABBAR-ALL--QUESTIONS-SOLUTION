#include <iostream>
#include <stack>
using namespace std;

/* Function to remove elements from the middle of a stack */
void solve(stack<int> &implementedStack, int count, int N) {
    if (count == N / 2) {
        implementedStack.pop(); // Remove the middle element
        return;
    }

    int num = implementedStack.top();
    implementedStack.pop();
    solve(implementedStack, count + 1, N);
    implementedStack.push(num);
}

/* Function to delete the middle element(s) from a stack */
void deleteMiddle(stack<int> &implementedStack, int N) {
    int count = 0;
    solve(implementedStack, count, N);
}

int main() {
    // Example usage
    stack<int> myStack;
    int N = 6;

    for (int i = 1; i <= N; i++) {
        myStack.push(i);
    }

    cout << "Stack before deletion:" << endl;
    stack<int> tempStack = myStack;
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    myStack = stack<int>(); // Clear the stack

    for (int i = 1; i <= N; i++) {
        myStack.push(i);
    }

    deleteMiddle(myStack, N);

    cout << "Stack after deletion:" << endl;
    tempStack = myStack;
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    return 0;
}
