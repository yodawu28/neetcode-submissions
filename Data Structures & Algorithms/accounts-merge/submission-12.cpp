struct Account {
    string name;
    unordered_set<string> emails;
};

class UniFind {
public:
    vector<Account*> accounts;
    unordered_map<int, int> parents;
    unordered_map<int, int> ranks;
    
    UniFind(const vector<vector<string>> &_accounts) {
        accounts.clear();
        for (int i = 0; i < _accounts.size(); i++) {
            vector<string> accountV = _accounts[i];
            
            Account* account = new Account();
            account->name = accountV[0];
            
            for (int j = 1; j < accountV.size(); j++) {
                account->emails.insert(accountV[j]);
            }
            
            accounts.push_back(account);
            
            parents[i] = i;
            ranks[i] = 0;
        }
    }
    
    int find(int x) {
        int root = parents[x];
        
        if (parents[root] != root) {
            return parents[x] = find(root);
        }
        
        return root;
    }
    
    bool isSameComponent(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);
        
        return parentX == parentY;
    }
    
    bool _union(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);
        
        if (parentX == parentY) {
            return false;
        }
        
        if (ranks[parentX] < ranks[parentY]) {
            parents[parentX] = parentY;
        } else if (ranks[parentX] > ranks[parentY]) {
            parents[parentY] = parentX;
        } else {
            parents[parentY] = parentX;
            ranks[parentX]++;
        }
        return true;
    }
    
    void mergeEmail(int x, int y) {
        accounts[x]->emails.merge(accounts[y]->emails);
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
    
        unordered_map<string, int> emailMap;
        
        vector<vector<int>> edges;
        for (int i = 0; i < accounts.size(); i++) {
            vector<string> account = accounts[i];
            for (int j = 1; j < account.size(); j++) {
                auto it = emailMap.find(account[j]);
                if (it == emailMap.end()) {
                    emailMap[account[j]] = i;
                } else {
                    edges.push_back({it->second, i});
                }
            }
        }
        
        UniFind f = UniFind(accounts);
        
        for (int i = 0; i < edges.size(); i++) {
            f._union(edges[i][0], edges[i][1]);
        }
        
        unordered_set<int> ansSet;
        for (int i = 0; i < accounts.size(); i++) {
            int parent = f.find(i);
            if (i != parent) {
                f.accounts[parent]->emails.merge(f.accounts[i]->emails);
                continue;
            }
            ansSet.insert(parent);
        }
        
        for (auto i : ansSet) {
            vector<string> item;
            item.push_back(f.accounts[i]->name);
            item.insert(item.end(),f.accounts[i]->emails.begin(), f.accounts[i]->emails.end());
            std::sort(item.begin() + 1, item.end());
            ans.push_back(item);
        }
        
        return ans;
    }
};