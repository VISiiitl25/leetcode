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
    map<int, int> mp;
    int maxa = -1;

    void recur(TreeNode* root, int level) {
        if (root == nullptr) return;

        if (root->left) {
            maxa = max(maxa, level );
            if (mp.find(level) == mp.end()) {
                mp[level] = root->left->val;
            }
            recur(root->left, level + 1);
        }
        if (root->right) {
            maxa = max(maxa, level);
            if (mp.find(level) == mp.end()) {
                mp[level] = root->right->val;
            }
            recur(root->right, level + 1);
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        recur(root, 0);
        mp[-1]=root->val;
        cout<<maxa;
        return mp[maxa];
    }
};
