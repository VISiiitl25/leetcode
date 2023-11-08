class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();int maxa=0;

        int l=0,r=0;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            if(sum<0){
                sum=0;
            }
            r++;
            maxa=max(maxa,sum);
        }
        l=0,r=0;
        sum=0;
        int mini=INT_MAX;
         while(r<n){
            sum+=nums[r];
            if(sum>0){
                sum=0;
            }
            r++;
            mini=min(mini,sum);
        }
        return max(maxa,abs(mini));
    }
};