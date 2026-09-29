class TrieNode {
public:
    unordered_map<char, TrieNode*> childrens;
    bool isWord;
    TrieNode() {
        isWord = false;
    }
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c: word) {
            auto it = curr->childrens.find(c);
            if (it == curr->childrens.end()) {
                curr->childrens[c] = new TrieNode();
            }
            curr = curr->childrens[c];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            auto it = curr->childrens.find(c);
            if (it == curr->childrens.end()) {
                return false;
            }
            curr = curr->childrens[c];
        }

        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c: prefix) {
            auto it = curr->childrens.find(c);
            if (it == curr->childrens.end()) {
                return false;
            }
            curr = curr->childrens[c];
        }

        return true;
    }
};
