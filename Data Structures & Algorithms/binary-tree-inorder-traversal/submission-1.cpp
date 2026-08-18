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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;

        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {
            if (curr != NULL) {
                if (curr->left != NULL) {
                    st.push(curr);
                    curr = curr->left;
                } else {
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            } else {
                curr = st.top();
                st.pop();
                res.push_back(curr->val);
                curr = curr->right;
            }
        }

        return res;
    }
};