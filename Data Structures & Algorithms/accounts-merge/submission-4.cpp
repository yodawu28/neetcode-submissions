struct Account {
    string name;
    unordered_set<string> emails;
};

vector<Account> accountV;

class UniFind {
public:
    unordered_map<int, int> parents;
    unordered_map<int, int> ranks;
    UniFind(int n) {
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 0;
        }
    }
    
    int find(int x) {
        if (x == parents[x]) {
            return x;
        }
        return find(parents[x]);
    }
    
    bool isSameComponent(int x, int y) {
        Account a = accountV[x];
        Account b = accountV[y];
        
        for (string email: a.emails) {
            auto it = b.emails.find(email);
            if (it != b.emails.end()) {
                return true;
            }
        }
        return false;
    }
    
    bool _union(int x, int y) {
        if (isSameComponent(x, y)) {
            int parentX = find(x);
            int parentY = find(y);
            
            if (ranks[parentX] < ranks[parentY]) {
                parents[parentX] = parentY;
            } else if (ranks[parentX] > parents[parentY]) {
                parents[parentY] = parentX;
            } else {
                parents[parentY] = parentX;
                ranks[parentX]++;
            }
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        accountV.clear();

        vector<vector<string>> ans;
    
        for (int i = 0; i < accounts.size(); i++) {
            vector<string> account = accounts[i];
            
            Account acc = Account();
            acc.name = account[0];
            for (int j = 1; j < account.size(); j++) {
                acc.emails.insert(account[j]);
            }
            accountV.push_back(acc);
        }
        
        UniFind f = UniFind(accountV.size());
        
        for (int i = 0; i < accountV.size() - 1; i++) {
            for (int j = i + 1; j  < accountV.size(); j++) {
                f._union(i, j);
            }
        }
        
        unordered_set<int> check;
        for (int i = 0; i < accountV.size(); i++) {
            int parent = f.find(i);
            auto it = check.find(parent);
            if (it != check.end()) {
                accountV[parent].emails.merge(accountV[i].emails);
                continue;
            }
            if (parent != i) {
                accountV[parent].emails.merge(accountV[i].emails);
            }
            check.insert(parent);
        }
        
        for (auto i : check) {
            vector<string> item;
            item.push_back(accountV[i].name);
            item.insert(item.end(),accountV[i].emails.begin(), accountV[i].emails.end());
            sort(item.begin() + 1, item.end());
            ans.push_back(item);
        }
        
        return ans;
    }
};