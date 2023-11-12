class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int, set<int>> stop;

        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                stop[routes[i][j]].insert(i);  
            }
        }

        queue<pair<int, int>> q;
        map<int, int> vis;
        q.push({source, 0});

        map<int, int> visb; 
        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            int st = current.first;
            int num = current.second;

            if (st == target) {
                return num;
            }

            if (vis.find(st) == vis.end()) {
                vis[st]++;
                for (auto bus : stop[st]) {
                    if (visb.find(bus) == visb.end()) {
                        visb[bus] = 1;
                        for (auto busstop : routes[bus]) {
                            q.push({busstop, num + 1});
                        }
                    }
                }
            }
        }

        return -1; 
    }
};