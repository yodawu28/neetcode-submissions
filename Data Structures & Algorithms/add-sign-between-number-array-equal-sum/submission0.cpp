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
int curr;

void helper(int n, int s, int idx)
{
    if (idx > n)
    {
        if (curr == s)
        {
            ans++;
        }
        return;
    }
    
    curr += idx;
    helper(n, s, idx + 1);
    curr -= idx;
    
    curr -= idx;
    helper(n, s, idx + 1);
    curr += idx;
}

int run(int n, int s)
{
    // 1 2 3 4
    ans = 0;
    curr = 1;
    
    helper(n, s, 2);
    
    cout << ans << endl;
    
    return ans;
}
