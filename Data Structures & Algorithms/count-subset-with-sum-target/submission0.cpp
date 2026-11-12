#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <set>
#include <iomanip>
#include <string>

using namespace std;

int ans;
int sum;

void helper(vector<int> &nums, int target, int idx)
{
    if (idx >= nums.size()) {
        if (sum == target) {
            ans += 1;
        }
        return;
    }
    
    if (sum + nums[idx] <= target) {
        sum += nums[idx];
        helper(nums, target, idx + 1);
        sum -= nums[idx];
    }
    // not choose
    helper(nums, target, idx + 1);
}

int countSum(vector<int> &nums, int target)
{
    ans = 0;
    sum = 0;
    helper(nums, target, 0);
    return ans;
}
