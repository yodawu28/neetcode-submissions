struct BrowserNode {
    string val;
    BrowserNode* next;
    BrowserNode* prev;

    BrowserNode() : val(""), next(nullptr), prev(nullptr) {}
    BrowserNode(string x) : val(x), next(nullptr), prev(nullptr) {}
};

class BrowserHistory {
public:
    BrowserNode* head;
    BrowserHistory(string homepage) {
        head = new BrowserNode(homepage);
    }
    
    void visit(string url) {
        BrowserNode* node = new BrowserNode(url);
        head->next = node;
        node->prev = head;
        head = node;
    }
    
    string back(int steps) {
        while (head->prev != NULL && steps > 0)
        {
            head = head->prev;
            steps--;
        }

        return head->val;
    }
    
    string forward(int steps) {
        while (head->next != NULL && steps > 0)
        {
            head = head->next;
            steps--;
        }

        return head->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */