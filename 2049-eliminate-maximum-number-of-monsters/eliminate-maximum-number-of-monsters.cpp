class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({speed[i], dist[i]});
        }

       
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return double(a.first*1.0 / a.second) > double(b.first*1.0 / b.second);
        });

        int c = 0, time = 0;
        for (int i = 0; i < n; i++) {
            if (v[i].first * time >= v[i].second) {
                break;
            } else {
                c++;
            }
            time++;
        }
        return c;
    }
};