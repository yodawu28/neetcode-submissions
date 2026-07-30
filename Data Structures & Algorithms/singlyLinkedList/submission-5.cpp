struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedList {
public:
    ListNode* head;
    LinkedList() {
        head = NULL;
    }

    int get(int index) {
        ListNode* curr = head;
        while (curr != NULL && index > 0)
        {
            curr = curr->next;
            index--;
        }

        if (curr == NULL)
        {
            return -1;
        }
        return curr->val;
    }

    void insertHead(int val) {
        if (head == NULL)
        {
            head = new ListNode(val);
        }
        else
        {
            ListNode* node = new ListNode(val);
            node->next = head;
            head = node;
        }
    }
    
    void insertTail(int val) {
        if (head == NULL)
        {
            head = new ListNode(val);
            return;
        }
        ListNode* curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        ListNode* node = new ListNode(val);
        curr->next = node;
    }

    bool remove(int index) {
        if (head == NULL)
        {
            return false;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        int idx = 0;
        while (curr != NULL && idx < index)
        {
            prev = curr;
            curr = curr->next;
            idx++;
        }

        if (idx > index || curr == NULL)
        {
            return false;
        }

        if (prev == NULL)
        {
            head = head->next;
        }
        else
        {
            prev->next = curr->next;
        }

        return true;
    }

    vector<int> getValues() {
        ListNode* curr = head;
        vector<int> values;
        while (curr != NULL)
        {
            values.push_back(curr->val);
            curr = curr->next;
        }

        return values;
    }
};
