class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        const int m = 1e9 + 7;

        unordered_map<int, int> mp;
        int ans = 0;

        for (int num : nums) {
            int reversed = 0;
            int temp = num;

            while (temp > 0) {
                reversed = reversed * 10 + temp % 10;
                temp /= 10;
            }

            int diff = num - reversed;
            ans = (ans + mp[diff]) % m;
            mp[diff]++;
        }

        return ans;
    }
};
