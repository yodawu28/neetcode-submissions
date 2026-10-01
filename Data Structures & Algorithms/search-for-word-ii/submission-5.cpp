class TrieNode {
public:
    unordered_map<char, TrieNode*> childs;
    bool isWord;
    TrieNode() {
        isWord = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    Trie(TrieNode* _root) {
        root = _root;
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
    
    Trie* search(char c) {
        auto it = root->childs.find(c);
        if(it == root->childs.end()) {
            return NULL;
        }
        
        return new Trie(it->second);
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

    void dfs(vector<vector<char>>& board, string s, int row, int col, Trie *trie) {
        visited[row][col] = 1;
        
        for (int i = 0; i < 4; i++) {
            int n_row = row + directions[i][0];
            int n_col = col + directions[i][1];
            
            if (isValid(board, n_row, n_col)) {
                s.push_back(board[n_row][n_col]);
                if (trie->isWord(board[n_row][n_col])) {
                    st.insert(s);
                }
                
                Trie* t = trie->search(board[n_row][n_col]);
                if (t) {
                    dfs(board, s, n_row, n_col, t);
                }
                s.pop_back();
                delete(t);
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
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (!visited[i][j]) {
                    if (trie.isWord(board[i][j])) {
                        string tmp = "";
                        tmp += board[i][j];
                        st.insert(tmp);
                    }
                    Trie* t = trie.search(board[i][j]);
                    if (t) {
                        string s = "";
                        s += board[i][j];
                        dfs(board, s, i, j, t);
                    }
                    delete(t);
                }
            }
        }
        
        for (string word: st) {
            ans.push_back(word);
        }
        
        return ans;
    }
};
