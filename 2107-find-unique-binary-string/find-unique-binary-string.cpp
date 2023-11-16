class Solution {
public:
map<string,int>mp;
    string recur(int i,int n,string temp){
        if(i==n){
            if(mp.find(temp)==mp.end()){
                return temp;
            }
            return "";
        }
        string t=temp+'0';
        string x=recur(i+1,n,t);
        string tt=temp+'1';
        string y=recur(i+1,n,tt);

        if(x!="")return x;
        if(y!="")return y;
        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        
        
        for(auto i:nums){
            mp[i]++;
        }
        return recur(0,nums.size(),"");
    }   
};