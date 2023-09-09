class Solution {
public:
    vector<int> dp;
    int recur(vector<int>& nums,int target){
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        if(dp[target]!=-1){
            return dp[target];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=recur(nums,target-nums[i]);
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp=vector<int> (target+1,-1);
        return recur(nums,target);
    }
};