class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int first=-1,second=-1;
        for(int i=1;i<=nums.size();i++){
            if(mp[i]==2)first=i;
            if(mp[i]==0)second=i;
        }
        return {first,second};
    }
};