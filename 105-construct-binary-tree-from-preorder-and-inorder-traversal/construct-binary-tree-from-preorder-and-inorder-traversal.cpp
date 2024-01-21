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
    TreeNode* ms(int i, int i1, int j1, vector<int>& preorder, vector<int>& inorder) {

        if (i == preorder.size()) return nullptr;
        if (i1 > j1) return nullptr;
        TreeNode* root = new TreeNode(preorder[i]);

        int ind = -1;
        for (int k = i1; k <= j1; k++) {
            if (inorder[k] == preorder[i]) {
                ind = k;
                break;
            }
        }
        root->left = ms(i + 1, i1, ind - 1, preorder, inorder);
        root->right = ms(i + ind - i1 + 1, ind + 1, j1, preorder, inorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return ms(0, 0, inorder.size() - 1, preorder, inorder);
    }
};
