class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt = 0;
    
        int L = 0, R = 0;
        int sum = 0;
        
        while (R < arr.size()) {
            while (R - L > k - 1) {
                sum -= arr[L];
                L++;
            }
            
            sum += arr[R];
            
            if (R - L == k - 1) {
                int avg = sum / abs(R-L + 1);
                if (avg >= threshold) {
                    cnt++;
                }
            }
            R++;
        }
        
        return cnt;
    }
};