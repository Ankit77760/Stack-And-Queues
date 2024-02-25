vector<int> nextGreaterElement(vector<int> &arr, int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                flag = 1;
                ans.push_back(arr[j]);
                break;
            }
        }

        if (flag == 0)
        {
            ans.push_back(-1);
        }
    }
    return ans;
}