class TrieNode {
public:
    unordered_map<char, TrieNode*> childs;
    bool isWord;
    TrieNode() {
        isWord = false;
    }
};

class Trie {
private:
    void clear(TrieNode* node) {
        if (node == nullptr) {
            return;
        }

        for (auto& [c, child] : node->childs) {
            clear(child);
        }

        delete node;
    }
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;

    ~Trie() {
        clear(root);
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            auto it = curr->childs.find(c);
            if (it == curr->childs.end()) {
                curr->childs[c] = new TrieNode();
            }
            curr = curr->childs[c];
        }
        curr->isWord = true;
    }
    
    TrieNode* search(char c) {
        auto it = root->childs.find(c);
        if(it == root->childs.end()) {
            return NULL;
        }
        
        return it->second;
    }
    
    bool isWord(char c) {
        auto it = root->childs.find(c);
        if (it == root->childs.end()) {
            return false;
        }
        
        return it->second->isWord;
    }
};

class Solution {
public:
    int visited[15][15];
    vector<string> ans;
    unordered_set<string> st;
    int directions[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int m, n;

    bool isValid(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || col < 0) {
            return false;
        }
        
        if (row > m || col > n) {
            return false;
        }
        
        if (visited[row][col]) {
            return false;
        }
        
        return true;
    }

    void dfs(vector<vector<char>>& board, string s, int row, int col, TrieNode *node) {
        visited[row][col] = 1;
        
        for (int i = 0; i < 4; i++) {
            int n_row = row + directions[i][0];
            int n_col = col + directions[i][1];
            
            if (isValid(board, n_row, n_col)) {
                s.push_back(board[n_row][n_col]);
                auto it = node->childs.find(board[n_row][n_col]);
                if (it != node->childs.end()) {
                    TrieNode* next = it->second;
                    if (next->isWord) {
                        st.insert(s);
                    }
                    
                    dfs(board, s, n_row, n_col, next);
                }
                s.pop_back();
            }
        }
        
        visited[row][col] = 0;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ans.clear();
        st.clear();
        
        if (board.empty()) {
            return ans;
        }
        
        // create Trie for words because we will search by word
        Trie trie = Trie();
        
        for (string word: words) {
            trie.insert(word);
        }
        
        // we will use DFS to find word
        m = board.size() - 1;
        n = board[0].size() - 1;
        
        string s = "";
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (!visited[i][j]) {
                    if (trie.isWord(board[i][j])) {
                        string tmp = "";
                        tmp += board[i][j];
                        st.insert(tmp);
                    }
                    TrieNode* node = trie.search(board[i][j]);
                    if (node) {
                        s.push_back(board[i][j]);
                        dfs(board, s, i, j, node);
                        s.pop_back();
                    }
                }
            }
        }
        
        for (string word: st) {
            ans.push_back(word);
        }
        
        return ans;
    }
};
