class Solution {
public:
    int check(vector<int>&nums,int mid){
        int c=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            auto it=upper_bound(nums.begin(),nums.end(),nums[i]+mid);
            int index;
            if(it==nums.end()){
                index=n;
            }
            else{
                index=it-nums.begin();
            }
            c+=(index-i-1);
        }
        return c;
    }
    int smallestDistancePair(vector<int>& nums, int k) {

     int n=nums.size();
     sort(nums.begin(),nums.end());

     int l=0,h=1e6;
    int ans=-1;
     while(l<=h) {
         int mid=(l+h)/2;

         int x=check(nums,mid);
        
          if(x<k){
             l=mid+1;
         }
         else{
             ans=mid;
             h=mid-1;
         }
     }  
     return ans;
    }
};