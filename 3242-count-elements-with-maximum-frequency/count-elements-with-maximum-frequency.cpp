class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int maxa=0;
        for(auto i:mp){
            maxa=max(maxa,i.second);
        }
        int ans=0;
        for(auto i:mp){
            if(mp[i.first]==maxa){
                ans+=maxa;
            }
        }
        return ans;

    }
};