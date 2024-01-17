#include <vector>
#include <stack>

using namespace std;

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
        stack<pair<TreeNode*, int>> st;
        vector<int> post;

        if (root == nullptr) {
            return post;
        }

        st.push({root, 1});

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            if (it.second == 1) {
                st.push({it.first, 2}); 
                if (it.first->left) {
                    st.push({it.first->left, 1});
                }
            } else if (it.second == 2) {
                st.push({it.first, 3});              if (it.first->right) {
                    st.push({it.first->right, 1});
                }
            } else {
                post.push_back(it.first->val);
            }
        }

        return post;
    }
};
