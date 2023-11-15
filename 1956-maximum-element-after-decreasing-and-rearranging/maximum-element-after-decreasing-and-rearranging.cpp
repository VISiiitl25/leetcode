class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        nums[0]=1;
        int last=1;
        for(int i=1;i<n;i++){
            if(nums[i]-last>1){
                nums[i]=last+1;
            }
            last=nums[i];
        }
        return nums[nums.size()-1];

    }
};