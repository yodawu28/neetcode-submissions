class TrieNode {
public:
    unordered_map<char, TrieNode*> childs;
    bool isWord;

    TrieNode() {
        isWord = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
    
    bool search(string word) {
        return searchTrie(word, 0, root);
    }

    bool searchTrie(const string &word, int idx, TrieNode* curr) {
        if (idx >= word.size()) {
            if (curr != NULL) {
                return curr->isWord;
            }
            return false;
        }

        bool isOk = false;
        if (word[idx] == '.') {
            for (auto i = curr->childs.begin(); i != curr->childs.end(); i++) {
                if (searchTrie(word, idx + 1, curr->childs[i->first])) {
                    isOk = true;
                    break;
                }
            }
        } else {
            auto it = curr->childs.find(word[idx]);
            if (it != curr->childs.end()) {
                isOk = searchTrie(word, idx + 1, curr->childs[word[idx]]);
            }
        }

        return isOk;
    }
};
