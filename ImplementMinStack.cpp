#include <bits/stdc++.h>
// Implement class for minStack.
class minStack
{

public:
    vector<pair<int, int> > st;
    // Constructor
    minStack()
    {
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        if (st.empty())
        {
            pair<int, int> p = make_pair(num, num);
            st.push_back(p);
        }
        else
        {
            pair<int, int> p;
            p.first = num;
            p.second = min(num, st.back().second);
            st.push_back(p);
        }
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        if (!st.empty())
        {
            int val = st.back().first;
            st.pop_back();
            return val;
        }
        else
        {
            return -1;
        }
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        if (!st.empty())
        {
            return st.back().first;
        }
        else
        {
            return -1;
        }
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        if (!st.empty())
        {
            return st.back().second;
        }
        else
        {
            return -1;
        }
    }
};