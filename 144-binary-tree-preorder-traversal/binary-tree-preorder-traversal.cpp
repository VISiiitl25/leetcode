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
    //  vector<int>ans2;
    // void pre(TreeNode* root){
    //     if(root==NULL)return;
    //     ans2.push_back(root->val);
    //     pre(root->left);
        
    //     pre(root->right);
        

    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     pre(root);
    //     return ans2;
    // }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;

        stack<TreeNode*>st;
        
        st.push(root);
        if(root==nullptr)return ans;

        while(!st.empty()){
            auto it=st.top();st.pop();
            ans.push_back(it->val);
            if(it->right)st.push(it->right);
            if(it->left)st.push(it->left);

        }
        return ans;
    }
};