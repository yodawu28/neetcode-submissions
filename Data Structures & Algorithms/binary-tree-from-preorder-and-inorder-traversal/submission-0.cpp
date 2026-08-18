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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return build(preIdx, 0, preorder.size() - 1, preorder, inorder);
    }

    int findIndex(int num, int start, int end, vector<int>& inorder) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == num) {
                return i;
            }
        }

        return -1;
    }

    TreeNode* build(int &preIdx, int start, int end, vector<int>& preorder, vector<int>& inorder) {
        if (start > end || preIdx >= preorder.size()) {
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[preIdx]);
        int rootIdx = findIndex(preorder[preIdx], start, end, inorder);

        preIdx++;
        node->left = build(preIdx, start, rootIdx - 1, preorder, inorder);
        node->right = build(preIdx, rootIdx + 1, end, preorder, inorder);

        return node;
    }
};
