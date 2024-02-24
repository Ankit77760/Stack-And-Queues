#include <bits/stdc++.h>
bool isValidParenthesis(string s)
{
    int n = s.size();
    stack<int> st;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            flag = 1;
            st.push(s[i]);
        }

        else
        {
            if (!st.empty())
            {
                char top = st.top();
                if (ch == '}' && top == '{' || ch == ']' && top == '[' || ch == ')' && top == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }

            else
            {
                return false;
            }
        }
    }

    if (st.empty() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}