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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        stack<pair<TreeNode*, bool>> st;

        st.push({root, false});

        while (!st.empty()) {
            pair<TreeNode*, bool> top = st.top();

            st.pop();

            TreeNode* curr = top.first;
            bool visited = top.second;

            if (!curr) {
                continue;
            }

            if (visited) {
                ans.push_back(curr->val);
            } else {
                st.push({curr, true});

                if (curr->right) {
                    st.push({curr->right, false});
                }

                if (curr->left) {
                    st.push({curr->left, false});
                }
            }
        }

        return ans;
    }
};