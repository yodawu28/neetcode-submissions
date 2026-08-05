class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
        {
            return;
        }

        if (m == 0)
        {
            for (int i = 0; i < n; i++)
            {
                nums1[i] = nums2[i];
            }
            return;
        }
        
        int end = m + n - 1;
        
        for(int i = n-1; i > -1; i--)
        {
            if (nums2[i] > nums1[m-1])
            {
                nums1[end] = nums2[i];
                end--;
                continue;
            }
            
            int j = m - 1;
            while (j >= 0 && nums1[j] > nums2[i])
            {
                j--;
            }
            j++;
            int k = end;
            while (k > j)
            {
                nums1[k] = nums1[k-1];
                k--;
            }
            nums1[k] = nums2[i];
        }
    }
};