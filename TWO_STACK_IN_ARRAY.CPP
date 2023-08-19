#include <iostream>
using namespace std;

class TwoStack // Capitalized the class name
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    TwoStack(int s) // Capitalized the constructor name
    {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int element)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = element;
        }
    }

    void push2(int element)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = element;
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        return -1; // Return a default value when stack1 is empty
    }

    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        return -1; // Return a default value when stack2 is empty
    }
};

int main()
{
    int s = 5;
    TwoStack tStack(s); // Capitalized the class name when creating an object

    tStack.push1(10);
    tStack.push2(20);
    tStack.push1(30);
    tStack.push2(40);

    int response = tStack.pop1();
    if (response != -1)
        cout << "Popped from stack1: " << response << endl;

    response = tStack.pop2();
    if (response != -1)
        cout << "Popped from stack2: " << response << endl;

    return 0;
}
