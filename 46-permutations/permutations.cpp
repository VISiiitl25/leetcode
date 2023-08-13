class Solution {
public:
    vector<vector<int>> ans;

    void recur(int i, int n, vector<int>& nums, vector<int>& temp) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < n; j++) {
            swap(nums[i], nums[j]);
            temp.push_back(nums[i]);
            recur(i + 1, n, nums, temp);
            temp.pop_back(); 
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        recur(0, nums.size(), nums, temp);
        return ans;
    }
};
