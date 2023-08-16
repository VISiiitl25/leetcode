class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        if (k == 1) return nums;
        int n = nums.size();
        
        deque<int> dq;
        int i = 0, j = 0;
        while (j < k) {
            while (!dq.empty() && nums[j] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        ans.push_back(nums[dq.front()]);

        for (int i = k; i < n; i++) {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
