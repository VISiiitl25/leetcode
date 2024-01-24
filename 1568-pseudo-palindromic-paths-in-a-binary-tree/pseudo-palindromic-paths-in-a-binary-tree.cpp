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
    int ans=0;
    map<int,int>mp;
    void dfs(TreeNode* root){
        if(root==nullptr)return ;
        mp[root->val]++;
        
        if(root->left==NULL&&root->right==NULL){
            int even=0,odd=0;
            for(auto i:mp){
                if(i.second%2)odd++;
                else even++;

                
            }
            if(odd<=1)ans++;
        }
        dfs(root->left);
        dfs(root->right);
        mp[root->val]--;
        if(mp[root->val]==0){
            mp.erase(root->val);
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return ans;
    }
};