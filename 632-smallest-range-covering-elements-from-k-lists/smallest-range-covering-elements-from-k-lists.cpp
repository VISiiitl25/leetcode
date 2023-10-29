class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n =nums.size();
        vector<pair<int,int>>elements;
        for (int i = 0; i < n; i++) {
            for (auto num : nums[i]) {
                elements.push_back({num, i});
            }
        }
        sort(elements.begin(),elements.end());
        n=elements.size();int req=nums.size();
        map<int,int>mp;
        int l=0,r=0;
        int tot=0;
        int mini=INT_MAX;
        int start=-1,end=-1;
        for(int r=0;r<n;r++){
            mp[elements[r].second]++;
            
            if(mp.size()==req){
            while(mp.size()==req){
                if(mp[elements[l].second]==1){
                    break;
                }
                else{
                    mp[elements[l].second]--;
                    l++;
                }
            }
            if(elements[r].first-elements[l].first +1<mini){
                mini=elements[r].first-elements[l].first +1;
                start=elements[l].first;
                end=elements[r].first;
            }
            }
        }
        return {start,end};
    }
};