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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        queue<TreeNode*> q;

        if (root == NULL) {
            return res;
        }

        q.push(root);

        while (!q.empty()) {
            vector<int> v;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                v.push_back(curr->val);

                if (curr->right) {
                    q.push(curr->right);
                }

                if (curr->left) {
                    q.push(curr->left);
                }
            }
            res.push_back(v[0]);
        }

        return res;
    }
};
