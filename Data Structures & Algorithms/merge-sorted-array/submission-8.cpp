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
        int n1 = m - 1;
        int n2 = n - 1;
        
        while (n2 > -1 && n1 > -1)
        {
            if (nums1[n1] <= nums2[n2])
            {
                nums1[end] = nums2[n2];
                n2--;
            }
            else
            {
                nums1[end] = nums1[n1];
                n1--;
            }
            end--;
        }
        
        if (n1 == -1)
        {
            for (int i = 0; i <= n2; i++)
            {
                nums1[i] = nums2[i];
            }
        }
    }
};