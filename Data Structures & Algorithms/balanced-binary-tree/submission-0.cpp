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
    int maxDiff = 0;
    int getHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = getHeight(root->left);
        int right = getHeight(root->right);

        maxDiff = max(maxDiff, abs(right - left));
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        getHeight(root);
        
        return maxDiff < 2;
    }
};
