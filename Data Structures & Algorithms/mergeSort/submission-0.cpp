// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        divide(pairs, 0, pairs.size() - 1);
        return pairs;
    }

    vector<Pair> divide(vector<Pair>& pairs, int start, int end)
    {
        if (start >= end)
        {
            return pairs;
        }
        
        int mid = (end - start) / 2 + start;

        divide(pairs, start, mid);
        divide(pairs, mid + 1, end); 

        merge(pairs, start, mid, end);

        return pairs;
    }

    vector<Pair> merge(vector<Pair>& pairs, int start, int mid, int end)
    {
        vector<Pair> left;
        vector<Pair> right;

        int n1 = mid - start + 1;
        int n2 = end - mid;

        for (int i = 0; i < n1; i++)
        {
            left.push_back(pairs[start + i]);
        }

        for (int i = 0; i < n2; i++)
        {
            right.push_back(pairs[mid + i + 1]);
        }

        int i = 0, j = 0, k = start;

        while (i < n1 && j < n2)
        {
            if (left[i].key <= right[j].key)
            {
                pairs[k] = left[i];
                i++;
            }
            else
            {
                pairs[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            pairs[k] = left[i];
            i++;
            k++;
        }


        while (j < n2)
        {
            pairs[k] = right[j];
            j++;
            k++;
        }

        return pairs;
    }
};
