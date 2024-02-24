#include <iostream>
#include <stack>

using namespace std;

class Queue
{
private:
    stack<int> primaryStack;   // For enqueue operation
    stack<int> secondaryStack; // For dequeue operation

public:
    // Function to check if the queue is empty
    bool isEmpty()
    {
        return primaryStack.empty() && secondaryStack.empty();
    }

    // Function to add an element to the queue
    void enqueue(int item)
    {
        primaryStack.push(item);
    }

    // Function to remove an element from the front of the queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        // If secondary stack is empty, move elements from primary to secondary stack
        if (secondaryStack.empty())
        {
            while (!primaryStack.empty())
            {
                secondaryStack.push(primaryStack.top());
                primaryStack.pop();
            }
        }

        // Pop the front element
        secondaryStack.pop();
    }

    // Function to get the front element of the queue without removing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1; // Return a default value indicating empty queue
        }

        // If secondary stack is empty, move elements from primary to secondary stack
        if (secondaryStack.empty())
        {
            while (!primaryStack.empty())
            {
                secondaryStack.push(primaryStack.top());
                primaryStack.pop();
            }
        }

        // Return the front element
        return secondaryStack.top();
    }
};

int main()
{
    Queue q;

    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl;

    return 0;
}
