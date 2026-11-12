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

vector<vector<int>> ans;
vector<int> subset;

void helper(int n, int idx)
{
    if (subset.size() >= n) {
        ans.push_back(subset);
        return;
    }
    
    if (idx > 0 && subset[idx-1] == 1)
    {
        subset.push_back(0);
        helper(n, idx + 1);
        subset.pop_back();
    } else {
        subset.push_back(0);
        helper(n, idx + 1);
        subset.pop_back();
        
        subset.push_back(1);
        helper(n, idx + 1);
        subset.pop_back();
    }
    
}

vector<vector<int>> generate(int n)
{
    ans.clear();
    subset.clear();
    
    helper(n, 0);
    return ans;
}
