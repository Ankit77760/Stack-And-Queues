#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100

class Stack
{
public:
    int arr[MAX_SIZE];
    int top;

    Stack()
    {
        top = -1;
    }

    void push(int data)
    {
        if (top >= MAX_SIZE)
        {
            cout << "Stack Overflow" << end;
            return;
        }
        arr[++top] = data;
        cout << data << " pushed in stack" << endl;
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Stack Undeflow";
            return;
        }
        cout << arr[top--] << " popped from stack" << endl;
    }

    int peek()
    {
        if (top < 0)
        {
            cout << "Stack Underflow";
            return -1;
        }
        cout << arr[top--];
        return arr[top];
    }

    bool isempty()
    {
        return (top < 0);
    }
};

class Stack
{

public:
    int Top;
    int *arr;
    int capacity;
    Stack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        Top = -1;
    }

    void push(int num)
    {
        if (isFull())
        {
            return;
        }
        Top++;
        arr[Top] = num;
    }

    int pop()
    {
        if (isEmpty())
        {
            return -1;
        }
        int val = arr[Top];
        Top--;
        return val;
    }

    int top()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[Top];
        }
    }

    int isEmpty()
    {
        if (Top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isFull()
    {
        if (Top == capacity - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
