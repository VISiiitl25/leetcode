class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        string ans="";
        for(int i=0;i<order.size();i++){
            int x=mp[order[i]];
            for(int j=0;j<x;j++){
                ans=ans+order[i];mp[order[i]]--;
            }
        }
        for(auto i:mp){
            if(i.second>0){
                int x=mp[i.first];
            for(int j=0;j<x;j++){
                char c=i.first;
                ans=ans+c;
            }
            }
        }
        return ans;
    }
};