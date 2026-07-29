class Solution {
public:
    int findMaxRight(vector<int>& arr, int start)
    {
        int n = arr.size();

        int j = start;
        int maxId = j;
        while (j < n)
        {
            if (arr[j] > arr[maxId])
            {
                maxId = j;
            }
            j++;
        }

        return maxId;
    }

    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxId = -1;

        for (int i = 0; i < n-1; i++)
        {
            if (maxId == -1 || i >= maxId)
            {
                maxId = findMaxRight(arr, i + 1);
            }
            arr[i] = arr[maxId];
        }

        arr[n-1] = -1;

        return arr;
    }
};