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
    bool check(TreeNode* root, int &currSum, int target) {
        if (!root) {
            return false;
        }

        currSum += root->val;

        if (!root->left && !root->right && currSum == target) {
            return true;
        }

        if (check(root->left, currSum, target)) {
            return true;
        }

        if (check(root->right, currSum, target)) {
            return true;
        }

        currSum -= root->val;

        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int currSum = 0;
        return check(root, currSum, targetSum);
    }
};