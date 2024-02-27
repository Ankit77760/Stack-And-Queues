#include <bits/stdc++.h>
vector<int> maxSlidingWindow(vector<int> &arr, int n, int k)
{
    vector<int> ans;
    int l = k;
    for (int i = 0; i < n; i++)
    {
        int maxi = arr[i];
        if ((i + k) > n)
        {
            break;
        }
        for (int j = i; j < i + k; j++)
        {
            maxi = max(arr[j], maxi);
        }
        ans.push_back(maxi);
    }
    return ans;
}

vector<int> maxSlidingWindow(vector<int> &arr, int n, int k)
{
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(arr[dq.front()]);
    }
    return ans;
}