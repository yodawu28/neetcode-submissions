#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <set>
#include <iomanip>
#include <string>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

typedef Node* Tree;

void createTree(Tree &t) {
    t = NULL;
}

Node* createNode(int x) {
    Node* t = new Node;
    if (t == NULL) {
        return NULL;
    }
    
    t->key = x;
    t->left = NULL;
    t->right = NULL;
    
    return t;
}

bool addNode(Tree &t, int x) {
    if (t != NULL) {
        if (t->key == x) {
            return false;
        } else if (t->key > x) {
            return addNode(t->left, x);
        } else {
            return addNode(t->right, x);
        }
    }
    
    t = createNode(x);
    return true;
}

void inorder(Tree t) {
    if (t == NULL) {
        return;
    }
    
    if (t->left != NULL) {
        inorder(t->left);
    }
    cout << t->key << " ";
    if (t->right != NULL) {
        inorder(t->right);
    }
}

void preorder(Tree t) {
    if (t == NULL) {
        return;
    }
    
    cout << t->key << " ";
    if (t->left != NULL) {
        preorder(t->left);
    }
    if (t->right != NULL) {
        preorder(t->right);
    }
}

Node* search(Tree t, int x) {
    if (t == NULL) {
        return t;
    }
    
    if (t->key == x) {
        return t;
    } else if (t->key > x) {
        return search(t->left, x);
    } else {
        return search(t->right, x);
    }
}

Node* findMaxLeft(Tree &t) {
    if (t->right == NULL) {
        return t;
    }
    
    return findMaxLeft(t->right);
}

void deleteNode(Tree &t, int x) {
    
    // find x in BTS
    if (t->key < x) {
        deleteNode(t->right, x);
    } else if (t->key > x) {
        deleteNode(t->left, x);
    } else {
        Node* d = t;
        if (t->left == NULL) {
            t = t->right;
        } else if (t->right == NULL) {
            t = t->left;
        } else {
            Node* maxLeft = findMaxLeft(t->left);
            t->key = maxLeft->key;
            deleteNode(t->left, maxLeft->key);
            return;
        }
        delete d;
    }
}

int main() {
    Tree bst;
    createTree(bst);
    
    vector<int> a = {12, 8, 23, 15, 2, 7, 9, 3, 25, 18};
    
    for (int i = 0; i < a.size(); i++) {
        addNode(bst, a[i]);
    }
    
    cout << "---Inoder Traversal---" << endl;
    inorder(bst);
    cout << endl;
    
    cout << "---Preorder Traversal---" << endl;
    preorder(bst);
    cout << endl;
    
    cout << "Enter value to search in BST.\nx=";
    int x;
    cin >> x;
    
    if (search(bst, x) == NULL) {
        cout << x << " is not exist in BTS" << endl;
    } else {
        cout << x << " is exist in BTS" << endl;
        char del;
        cout << "Do you want remove " << x << " to BTS ? c/k: ";
        cin >> del;
        if (del == 'c') {
            deleteNode(bst, x);
            cout << "BST after delete " << x << endl;
            inorder(bst);
            cout << endl;
        }
    }
    
    return 1;
}
