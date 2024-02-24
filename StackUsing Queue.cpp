#include <iostream>
#include <queue>

using namespace std;

class Stack
{
private:
    queue<int> primaryQueue; // Main storage for elements
    queue<int> helperQueue;  // Helper queue for pushing and popping elements

public:
    // Function to check if the stack is empty
    bool isEmpty()
    {
        return primaryQueue.empty();
    }

    // Function to push an element onto the stack
    void push(int item)
    {
        // Move all elements from primaryQueue to helperQueue
        while (!primaryQueue.empty())
        {
            helperQueue.push(primaryQueue.front());
            primaryQueue.pop();
        }

        // Enqueue the new element
        primaryQueue.push(item);

        // Move elements back to primaryQueue from helperQueue
        while (!helperQueue.empty())
        {
            primaryQueue.push(helperQueue.front());
            helperQueue.pop();
        }
    }

    // Function to remove the top element from the stack
    void pop()
    {
        if (!isEmpty())
        {
            primaryQueue.pop();
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }

    // Function to get the top element of the stack without removing it
    int top()
    {
        if (!isEmpty())
        {
            return primaryQueue.front();
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1; // Return a default value indicating empty stack
        }
    }
};

int main()
{
    Stack s;

    cout << "Is the stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Top element: " << s.top() << endl;

    s.pop();
    cout << "Top element after pop: " << s.top() << endl;

    return 0;
}
