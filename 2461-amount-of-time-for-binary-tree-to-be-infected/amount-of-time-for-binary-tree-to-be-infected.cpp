
class Solution {
public:
    vector<int>adj[100005];

    void printGraph(int nodes) {
    for (int i = 1; i <= nodes; i++) {
        cout << "Node " << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}
    void inorder(TreeNode* root){
        if(!root)return;

        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            inorder(root->left);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            inorder(root->right);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        
        inorder(root);

        queue<pair<int,int>>q;
        vector<bool> visited(100005, false);
        
        q.push({start,0});
        int maxa=0;
        while(!q.empty()){
            auto it=q.front();
            visited[it.first]=true;
            q.pop();
            for(auto i: adj[it.first]){
                if(!visited[i]){
                q.push({i,it.second+1});
                maxa=max(maxa,it.second+1);}
            }
        }
        
        return maxa;
    }
};