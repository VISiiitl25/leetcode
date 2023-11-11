class Graph {
public:
    #define INF 0x3f3f3f3f
    vector<pair<int, int>> adj[101];

    Graph(int n, vector<vector<int>>& edges) {
        for (auto edge : edges)
            adj[edge[0]].emplace_back(edge[1], edge[2]);
    
    }

    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2) {
        vector<int> dist(101, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int src = node1;
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
                int v = (*i).first;
                int weight = (*i).second;
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[node2] == INF ? -1 : dist[node2];
    }
};
