class Solution {
public:
    // typedef pair<int, int> pi; 
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        typedef pair<int, int> pi;
        vector<vector<pair<int, int>>> v(n+1);
        for (auto i : times) {
            v[i[0]].push_back({i[2], i[1]});
        }
        vector<int> dis(n+1, 1e8); 
        dis[k] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto it = pq.top(); 
            int src = it.second;
            int dist = it.first;        
            pq.pop();
            for (auto i : v[src]) {
                if (dis[i.second] > dist + i.first) {
                    dis[i.second] = dist + i.first;
                    pq.push({dis[i.second], i.second});
                }
            }
        }

        int maxa = 0;
        for (int i=1;i<=n;i++) {
            if (dis[i] == 1e8) {
                return -1; }
            maxa = max(maxa, dis[i]);
        }
        return maxa;
    }
};
