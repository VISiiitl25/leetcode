class Solution {
public:
    int maxm =-1;
    void dfs(TreeNode* root,map<int,int> &m){
        if(root==NULL) return ;
        m[root->val]++;
        maxm = max(maxm,m[root->val]);
        dfs(root->left,m);
        dfs(root->right,m);
    }
   static bool comp(pair<int,int> & a,pair<int,int> & b){
       return a.first>b.first;
   }
    vector<int> findMode(TreeNode* root) {
        map<int,int> m;
       vector<int> ans;
        dfs(root,m);
        for(auto it =m.begin();it!=m.end();it++){
           if(it->second==maxm) ans.push_back(it->first);
        }
        return ans;
       
    }
};