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
    map<int, int> m;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;

        for (int i = 0; i < inorder.size(); i++) {
            m.insert({inorder[i], i});
        }

        return build(preIdx, 0, preorder.size() - 1, preorder, inorder);
    }

    TreeNode* build(int &preIdx, int start, int end, vector<int>& preorder, vector<int>& inorder) {
        if (start > end || preIdx >= preorder.size()) {
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[preIdx]);
        int rootIdx = m[preorder[preIdx]];

        preIdx++;
        node->left = build(preIdx, start, rootIdx - 1, preorder, inorder);
        node->right = build(preIdx, rootIdx + 1, end, preorder, inorder);

        return node;
    }
};
