struct Account {
    string name;
    unordered_set<string> emails;
};

class UniFind {
public:
    vector<Account*> accounts;
    unordered_map<int, int> parents;
    unordered_map<int, int> ranks;
    
    UniFind(vector<vector<string>> &_accounts) {
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
        if (x == parents[x]) {
            return x;
        }
        return find(parents[x]);
    }
    
    bool isSameComponent(int x, int y) {
        Account* a = accounts[x];
        Account* b = accounts[y];
        
        for (string email: a->emails) {
            auto it = b->emails.find(email);
            if (it != b->emails.end()) {
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
    
    void mergeEmail(int x, int y) {
        accounts[x]->emails.merge(accounts[y]->emails);
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
    
        UniFind f = UniFind(accounts);
        
        for (int i = 0; i < accounts.size() - 1; i++) {
            for (int j = i + 1; j < accounts.size(); j++) {
                f._union(i, j);
            }
        }
        
        unordered_set<int> ansSet;
        for (int i = 0; i < accounts.size(); i++) {
            int parent = f.find(i);
            if (parent != i) {
                f.mergeEmail(parent, i);
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