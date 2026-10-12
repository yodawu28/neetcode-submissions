/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    queue<TreeNode*> q;
    BSTIterator(TreeNode* root) {
        traversal(root);
    }

    void traversal(TreeNode* root) {
        if (!root) {
            return;
        }

        if (root->left) {
            traversal(root->left);
        }
        
        q.push(root);
        
        if (root->right) {
            traversal(root->right);
        }
    }
    
    int next() {
        int val = q.front()->val;
        q.pop();
        return val;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */