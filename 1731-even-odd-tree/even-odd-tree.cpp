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
    bool issorted(vector<int>temp){
        for(int i=1;i<temp.size();i++){
            if(temp[i]<=temp[i-1])return false;
           
        }
         return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>>ans;
                if(root==NULL){
            return true;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
           int s=q.size();
           vector<int>level;
           for(int i=0;i<s;i++){
               TreeNode* n=q.front();
               level.push_back(n->val);
               if(n->left!=NULL){
                   q.push(n->left);
               }
               if(n->right!=NULL){
                   q.push(n->right);
               }
               q.pop();
           }
           ans.push_back(level);
        }

        for(int i=0;i<ans.size();i++){
            for(auto j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;}
        
        for(int i=0;i<ans.size();i++){
            if(i%2==0){
                for(auto j:ans[i]){
                    if(j%2==0)return false;
                }
                if(!issorted(ans[i]))return false;
            }
            else{
                for(auto j:ans[i]){
                    if(j%2==1)return false;
                }
                reverse(ans[i].begin(),ans[i].end());
                if(!issorted(ans[i]))return false;
            }
        }
        return true;


    }
};