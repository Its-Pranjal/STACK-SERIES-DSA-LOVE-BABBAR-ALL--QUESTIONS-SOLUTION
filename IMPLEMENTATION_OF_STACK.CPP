#include<iostream>
using namespace std;

/* A simple stack implementation */
class Stack {

public:
    int *arr;
    int top;
    int size;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if (top < size - 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack is overflow" << endl;
        }
    }

    void pop() {
        if (top > -1) {
            top--;
        } else {
            cout << "Stack underflow" << endl;
        }
    }

    int peek() {
        if (top >= 0 && top < size) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1; // Return a default value when the stack is empty
        }
    }

    bool isEmpty() {
        return top == -1; // Simplified implementation of isEmpty()
    }
};

int main() {
    // Example usage
    Stack myStack(5);

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top element: " << myStack.peek() << endl;

    myStack.pop();
    cout << "Top element after pop: " << myStack.peek() << endl;

    if (myStack.isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}
