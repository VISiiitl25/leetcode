class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        set<int>s;map<int,int>mp;
        for(auto i:arr){mp[i]++;}
        map<int,int>mp2;
        for(auto i:mp){mp2[i.second]++;
        s.insert(i.second);}
        return mp.size()==mp2.size();

        
    }
};