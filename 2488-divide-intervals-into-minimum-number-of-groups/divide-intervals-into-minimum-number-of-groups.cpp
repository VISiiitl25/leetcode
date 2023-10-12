#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> d;
        for (const auto& interval : intervals) {
            int l = interval[0];
            int r = interval[1];
            d[l]++;
            d[r + 1]--;
        }

        int overlaps = 0;
        int res = 0;
        for (auto kv : d) {
            overlaps += kv.second;
            res = max(res, overlaps);
        }
        
        return res;
    }
};
