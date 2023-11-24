class Solution {
public:
    int maxCoins(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int l=0,h=nums.size()-2;
        int ans=0;
        while(l<h){
            ans+=nums[h];
            h-=2;
            l++;
        }
        return ans;
    }
};