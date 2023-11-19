class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int last=nums[0];
        int lastv=0;
        
        map<int,int>mp;mp[last]=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i]!=last){
                mp[nums[i]]=lastv+1;
                last=nums[i];
                lastv++;
            }
        }
        int ans=0;

        for(int i=0;i<nums.size();i++){
            ans+=mp[nums[i]];
        }
        return ans;
    }
};