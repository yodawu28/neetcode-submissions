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
vector<vector<int>> ans;
vector<int> subset;
int current;

void helper(int n, int id)
{
    if (n <= 0) {
        ans.push_back(subset);
        return;
    }
    
    for (int i = id; i <= n; i++)
    {
        subset.push_back(i);
        n -= i;
        helper(n, i);
        subset.pop_back();
        n += i;
    }
    
}

vector<vector<int>> run(int n)
{
    current = 0;
    helper(n,1);
    return ans;
}

int main()
{
    int n = 4;
    run(n);
    
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << ans.size() << endl;
}
