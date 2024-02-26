void immediateSmaller(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = i + 1; j == i + 1; j++)
        {
            if (arr[j] < arr[i])
            {
                flag = 1;
                arr[i] = arr[j];
                break;
            }
        }
        if (i == n - 1)
        {
            arr[i] = -1;
            break;
        }
        if (flag == 0)
        {
            arr[i] = -1;
        }
    }
}
