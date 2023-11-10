#include <vector>

class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<int>& result, vector<int> adj[]) {
        visited[node] = true;
        result.push_back(node - 100000); 

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, result, adj);
                break; 
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>>& ad) {
        vector<int> adj[200001];

        for (int i = 0; i < ad.size(); i++) {
            adj[100000 + ad[i][0]].push_back(ad[i][1] + 100000);
            adj[100000 + ad[i][1]].push_back(ad[i][0] + 100000);
        }

        int p = 0;
        for (int i = 0; i < 200001; i++) {
            if (adj[i].size() == 1) {
                p = i;
                break;
            }
        }

        vector<int> result;
        vector<bool> visited(200001, false);

        dfs(p, visited, result, adj);

        return result;
    }
};
