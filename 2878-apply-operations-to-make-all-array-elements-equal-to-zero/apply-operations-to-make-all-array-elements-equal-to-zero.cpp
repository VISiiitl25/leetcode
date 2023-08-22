class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>temp(n+1,0);
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=temp[i];
            nums[i]-=curr;
            if(nums[i]<0)return false;

            curr+=nums[i];
            if((i+k)<= n){
                temp[i+k] -= nums[i];
                nums[i] = 0;
            }
        }
        for(int i=0;i<n;++i){
            if(nums[i])return false;
        }
        return true;
    }
};