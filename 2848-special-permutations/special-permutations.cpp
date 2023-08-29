class Solution
{
    public:
        int m = pow(10, 9) + 7;
    vector<vector<vector< int>>> dp;

    int recur(int i, vector<int> &nums, int last, int mask)
    {
        if (i == nums.size())
        {
            return 1;
        }

        if (dp[i][last + 1][mask] != -1)
        {
            return dp[i][last + 1][mask];
        }

        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (!(mask &(1 << j)))
            {
                if (last == -1 || nums[last] % nums[j] == 0 || nums[j] % nums[last] == 0)
                {
                    count += recur(i + 1, nums, j, mask ^ (1 << j));
                    count %= m;
                }
            }
        }

        return dp[i][last + 1][mask] = count;
    }

    int specialPerm(vector<int> &nums)
    {
        int n = nums.size();
        int mask = 0;
        dp.assign(n + 1, vector<vector < int>> (n + 1, vector<int> (1 << n, -1)));

        return recur(0, nums, -1, mask);
    }
};