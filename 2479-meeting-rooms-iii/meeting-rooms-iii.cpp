
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        map<long long, int> ans;
        sort(meetings.begin(), meetings.end());
        priority_queue<long long, vector<long long>, greater<long long>> av; 
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> run; // Change pair types to long long

        for (long long i = 1; i <= n; i++) {
            av.push(i);
        }

        for (long long i = 0; i < meetings.size(); i++) { 
            long long start = meetings[i][0];
            while (!run.empty() && run.top().first <= start) {
                av.push(run.top().second);
                run.pop();
            }
            if (!av.empty()) {
                long long room = av.top();
                av.pop();
                ans[room]++;
                run.push({meetings[i][1], room});
            } else {
                auto tt = run.top();
                run.pop();
                long long extra = tt.first - meetings[i][0];
                long long room = tt.second;
                ans[room]++;
                run.push({meetings[i][1] + extra, room});
            }
        }

        long long maxa = 0, jj = 0;
        for (auto i : ans) {
            if (i.second > maxa) {
                maxa = i.second;
                jj = i.first;
            }
        }
        return jj - 1;
    }
};
