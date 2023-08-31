class Solution
{
    public:
        int countSubarrays(vector<int> &nums, int k)
        {

            map<int, int> mp;
            int ind = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == k)
                {
                    ind = i;
                }
            }

            int c = 0;
            mp[0]++;
            for (int i = ind + 1; i < n; i++)
            {
                if (nums[i] > k)
                {
                    c++;
                }
                else
                {
                    c--;
                }
                mp[c]++;
            }
            c = 0;

            int cnt = 0;

            cnt += (mp.find(0 - c) != mp.end() ? mp[0] : 0);
            cnt += (mp.find(1 - c) != mp.end() ? mp[1 - c] : 0);
            for (int i = ind - 1; i >= 0; i--)
            {
                if (nums[i] > k)
                    c++;
                else
                    c--;

                cnt += (mp.find(0 - c) != mp.end() ? mp[0-c] : 0);
                cnt += (mp.find(1 - c) != mp.end() ? mp[1 - c] : 0);
            }
            return cnt;
            
        }
};