class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int l=0,h=nums.size()-1;
        int maxa=0;
        while(l<h){
            maxa=max(maxa,nums[l]+nums[h]);
            l++;h--;
        }
        return maxa;
    }
};