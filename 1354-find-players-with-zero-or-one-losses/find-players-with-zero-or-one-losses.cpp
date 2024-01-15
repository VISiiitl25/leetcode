class Solution {
public:

    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int,int>mp
        ;
        set<int>s;
        int maxa=0;
        for(auto it:matches){
            mp[it[1]]++;
           
            maxa=max({maxa,it[0],it[1]});
            s.insert(it[0]);
            s.insert(it[1]);
        }
        vector<int>v1,v2;
        for(auto i:s){
                if(mp[i]==0){
                v1.push_back(i);
            }
            if(mp[i]==1){
                v2.push_back(i);
            }
        }
        
        return {v1,v2};
    }
};