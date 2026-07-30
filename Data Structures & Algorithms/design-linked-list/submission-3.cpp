struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class MyLinkedList {
public:
    ListNode* head;
    int length = 0;
    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        ListNode* curr = head;
        while (curr != NULL && index > 0)
        {
            index--;
            curr = curr->next;
        }

        if (curr == NULL)
        {
            return -1;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        if (head == NULL)
        {
            head = node;
        }
        else
        {
            node->next = head;
            head->prev = node;
            head = node;
        }
        length++;
    }
    
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        if (head == NULL)
        {
            head = node;
            return;
        }

        ListNode* curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = node;
        node->prev = curr;
        length++;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* curr = head;
        ListNode* node = new ListNode(val);
        if (index == length)
        {
            // insert tail
            addAtTail(val);
            return;
        }
        else if (index > length) 
        {
            // not insert
            return;
        }

        while (curr->next != NULL && index > 0)
        {
            curr = curr->next;
            index--;
        }

        curr->prev->next = node;
        node->prev = curr->prev;
        node->next = curr;
        curr->prev = node;

        length++;
    }
    
    void deleteAtIndex(int index) {
        if (index > length)
        {
            return;
        }

        ListNode* curr = head;

        while (curr != NULL && index > 0)
        {
            index--;
            curr = curr->next;
        }

        if (curr != NULL)
        {
            ListNode* next = curr->next;
            curr->prev->next = next;
            if (next != NULL)
            {
                next->prev = curr->prev;
            }
        }

        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */