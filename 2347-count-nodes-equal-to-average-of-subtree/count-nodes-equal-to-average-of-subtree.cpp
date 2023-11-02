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
    int count=0;
    pair<int,int> func(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        int sum=root->val;
        int cnt=1;
        auto i=func(root->left);
        sum+=i.first;cnt+=i.second;
        auto it=func(root->right);
        sum+=it.first;cnt+=it.second;

        if(sum/cnt ==root->val){
            count++;
        }
        return {sum,cnt};



    }
    int averageOfSubtree(TreeNode* root) {
        
        func(root);

        return count;
    }
};