struct Node {
    int val;
    Node* next;
    Node* prev;

    Node() : val(0), next(nullptr), prev(nullptr) {}
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class Deque {
public:
    Node* head;
    Node* tail;
    int length;
    Deque() {
        head = new Node();
        tail = new Node();
        length = 0;
    }

    bool isEmpty() {
        return length == 0;
    }

    void append(int value) {
        Node* node = new Node(value);
        if (isEmpty())
        {
            head->next = node;
            node->prev = head;

            node->next = tail;
            tail->prev = node;
        }
        else
        {
            Node* prev = tail->prev;

            prev->next = node;
            node->prev = prev;

            node->next = tail;
            tail->prev = node;
        }

        length++;
    }

    void appendleft(int value) {
        Node* node = new Node(value);
        if (isEmpty())
        {
            head->next = node;
            node->prev = head;

            node->next = tail;
            tail->prev = node;
        }
        else
        {
            Node* next = head->next;
            node->next = next;
            next->prev = node;

            head->next = node;
            node->prev = head;
        }

        length++;
    }

    int pop() {
        if (isEmpty())
        {
            return -1;
        }
        Node* node = tail->prev;
        Node* prev = node->prev;

        prev->next = tail;
        tail->prev = prev;

        length--;

        return node->val;
    }

    int popleft() {
        if (isEmpty()) {
            return -1;
        }

        Node* node = head->next;
        head->next = node->next;
        node->next->prev = head;

        length--;

        return node->val;
    }
};
