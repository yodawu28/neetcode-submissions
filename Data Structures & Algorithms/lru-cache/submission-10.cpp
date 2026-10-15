class Node {
public:
    int val;
    int key;
    Node* prev;
    Node* next;
    Node(int _val, int _key) {
        val = _val;
        key = _key;
    }
};

class TreeNode {
public:
    Node* head;
    Node* tail;
    TreeNode() {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        
        head->next = tail;
        tail->prev = head;
    }
    
    void addTail(Node* node) {
        Node* prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        
        node->next = tail;
        tail->prev = node;
    }
    
    Node* getHead() {
        return head->next;
    }
    
    void removeHead() {
        Node* next = head->next;
        if (next && next->next) {
            head->next = next->next;
            next->next->prev = head;
        }
    }
};

class LRUCache {
public:
    TreeNode* tree;
    int _capacity;
    unordered_map<int, Node*> m;
    LRUCache(int capacity) {
        _capacity = capacity;
        tree = new TreeNode();
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) {
            return -1;
        }
        Node* curr = m[key];
        
        Node* next = curr->next;
        Node* prev = curr->prev;
        
        prev->next = next;
        next->prev = prev;
        
        tree->addTail(curr);
        
        return curr->val;
    }
    
    void put(int key, int value) {
        Node* node = new Node(value, key);
        if (m.size() < _capacity) {
            // check key is exist
            auto it = m.find(key);
            if (it == m.end()) {
                tree->addTail(node);
                m[key] = node;
                return;
            } else {
                Node* curr = m[key];
                
                Node* next = curr->next;
                Node* prev = curr->prev;
                
                prev->next = next;
                next->prev = prev;
                
                curr->val = value;
                
                tree->addTail(curr);
            }
            return;
        }
        
        auto it = m.find(key);
        if (it == m.end()) {
            Node* top = tree->getHead();
            tree->removeHead();
            m.erase(top->key);
            tree->addTail(node);
            m[key] = node;
        } else {
            Node* curr = m[key];
            
            Node* next = curr->next;
            Node* prev = curr->prev;
            
            prev->next = next;
            next->prev = prev;
            
            curr->val = value;
            
            tree->addTail(curr);
        }
    }
};
