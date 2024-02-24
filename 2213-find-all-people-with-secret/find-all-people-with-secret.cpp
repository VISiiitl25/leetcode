class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto i : meetings) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        vector<int> ans;
        ans.push_back(firstPerson);ans.push_back(0);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        set<int> visited;

        q.push({0, firstPerson});
        q.push({0,0});

        while (!q.empty()) {
            int time = q.top().first;
            int tel = q.top().second;
            q.pop();
            visited.insert(tel);
            for (auto i : adj[tel]) {
                if (i.second >= time && visited.find(i.first) == visited.end()) {
                    ans.push_back(i.first);
                    q.push({i.second, i.first}); 
                    
                }
            }
        }

        set<int> s(ans.begin(), ans.end());  
        ans.assign(s.begin(), s.end());      
        return ans;
    }
};
