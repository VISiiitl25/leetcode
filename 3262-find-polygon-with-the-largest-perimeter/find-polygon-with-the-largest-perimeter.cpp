class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans=-1;
        sort(nums.begin(),nums.end());
        long long sum=0;
        int n=nums.size();
        int cur=0;
        for(int i=0;i<n;i++){
            if(sum<=nums[i]){
                sum+=nums[i];cur++;                
            }
            else if(sum>nums[i]){
                sum+=nums[i];             
                cur++;
                if(cur>=3){
                    ans=max(ans,sum);
                }
            }
                    }
        return ans;
    }
};