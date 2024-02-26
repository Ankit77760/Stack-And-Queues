vector<int> nextGreaterElementII(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        int l = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                l = 1;
                ans.push_back(arr[j]);
                flag = 1;
                break;
            }
        }
        if (l == 0)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] > arr[i])
                {
                    ans.push_back(arr[j]);
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
        {
            ans.push_back(-1);
        }
    }
    return ans;
}
