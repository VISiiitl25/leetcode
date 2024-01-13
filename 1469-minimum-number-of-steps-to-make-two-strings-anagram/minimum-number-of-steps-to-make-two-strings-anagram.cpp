class Solution {
public:
    int minSteps(string s, string t) {
        map<int,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mp[t[i]]--;
        }
        int ans=0;
        int minus=0,plus=0;
        for(auto i:mp){
            cout<<i.first<<" "<<i.second<<endl;
            if(i.second>0)plus+=i.second;
            else if(i.second<0)minus+=abs(i.second);
        }
        ans=min(plus,minus);
        ans=ans+(plus-ans)+(minus-ans);cout<<endl;
        return ans;
    }
};