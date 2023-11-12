
class Solution {
public:
    long long maxSpending(vector<vector<int>>& a) {
        
        int m = a.size();
        int n = a[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        
        for(int i = 0; i < m; i++){
            pq.push({a[i].back(), i});
        }
        
        long long ans = 0;
        
        for(int i = 0; i < m * n; i++){
            auto it = pq.top();
            int x = it.first;
            int index = it.second;
            
            ans += 1LL*(i + 1) * x;
            pq.pop();
            
            a[index].pop_back();
            
            if (!a[index].empty()) {
                pq.push({a[index].back(), index});
            }
        }
        return ans;
    }
};
