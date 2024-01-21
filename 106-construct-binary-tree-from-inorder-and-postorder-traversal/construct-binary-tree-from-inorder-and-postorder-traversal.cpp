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
    TreeNode* ms(int i1, int j1, int i2, int j2, vector<int>& inorder, vector<int>& postorder) {

        if (i1 > j1 || i2 > j2) return nullptr;

        TreeNode* root = new TreeNode(postorder[j2]);
        int ind = -1;
        for (int k = i1; k <= j1; k++) {
            if (postorder[j2] == inorder[k]) {
                ind = k;
                break;
            }
        }

        root->left = ms(i1, ind - 1, i2, i2 + ind - i1 - 1, inorder, postorder);
        root->right = ms(ind + 1, j1, i2 + ind - i1, j2 - 1, inorder, postorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return ms(0, n - 1, 0, n - 1, inorder, postorder);
    }
};
