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
    vector<Pair> quickSort(vector<Pair>& pairs) {
        return quickSortPair(pairs, 0, pairs.size() - 1);
    }

    vector<Pair> quickSortPair(vector<Pair>& pairs, int s, int e) {
        if (s >= e) {
            return pairs;
        }

        int left = s;
        Pair pivot = pairs[e];

        for (int i = s; i <= e; i++)
        {
            if (pairs[i].key < pivot.key)
            {
                Pair tmp = pairs[i];
                pairs[i] = pairs[left];
                pairs[left] = tmp;

                left++;
            }
        }

        pairs[e] = pairs[left];
        pairs[left] = pivot;

        quickSortPair(pairs, s, left - 1);
        quickSortPair(pairs, left + 1, e);

        return pairs;
    }
};
