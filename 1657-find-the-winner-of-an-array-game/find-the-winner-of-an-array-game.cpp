class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        int maxa=max(arr[0],arr[1]);
        map<int,int>mp;
        for(int i=1;i<arr.size();i++){
            maxa=max(maxa,arr[i]);
            mp[maxa]++;
            if(mp[maxa]>=k)return maxa;
            
        }
       
       return maxa;
    }
};