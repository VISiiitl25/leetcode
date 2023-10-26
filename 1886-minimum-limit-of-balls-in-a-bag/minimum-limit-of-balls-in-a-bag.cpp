class Solution {
public:
    bool possible(int mid,vector<int>&nums,int maxo){

        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid){
                if(nums[i]%mid==0){
                    c+=(nums[i]/mid   -1);
                    
                }
                else{
                    c+=(nums[i]/mid);
                }
            }
        }
        return c<=maxo;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int l=1,h=1e9;
        int nas=0;
        while(l<=h){
            int mid=(l+h)/2;

            if(possible(mid,nums,maxOperations)){
                nas=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return nas;
    }
};