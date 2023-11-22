
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        int x= 1e5 + 1;
        vector<pair<int, int>> sum[x];

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                int su = i + j;
                sum[su].push_back({i, nums[i][j]});
            }
        }

        for (int i = 0; i < 1e5+1; i++) {
            sort(sum[i].begin(), sum[i].end(), greater<pair<int, int>>());
            for (auto p : sum[i]) {
                ans.push_back(p.second);
            }
        }

        return ans;
    }
};
