class Solution {
public:
    bool check(vector<int>& nums, int mid, int k) {
        int currsum = 0;
        int c = 1; int n = nums.size();

        for (int i = 0; i < n; ++i) {
            currsum += nums[i];
            if (currsum > mid) {
                currsum = nums[i];
                if(currsum>mid)return 0;
                c++;
            }
        }

    return c <= k; 
}

    int splitArray(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        int l=0,h=1e9;
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(nums,mid,k)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
       

    }
};