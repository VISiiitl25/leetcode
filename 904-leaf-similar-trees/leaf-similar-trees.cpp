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
    vector<int>v;
    void preorder(TreeNode *root){
        if(root->left==NULL&& root->right==NULL){
            v.push_back(root->val);
        }
        if(root->left){
        preorder(root->left);}
        if(root->right){
        preorder(root->right);}
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        preorder(root1);
        vector<int>v1=v;
        v.clear();
        preorder(root2);
        
        return v1==v;
    }
};