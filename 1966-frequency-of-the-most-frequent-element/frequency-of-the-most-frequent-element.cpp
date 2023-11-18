class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long pre[n+1];
        pre[0] = 0;
        for(int i = 0;i<n;i++){
            pre[i+1] = pre[i]+nums[i];
        }
        int ans =0;
        for(long long i = 1;i<=1e5;i++){
            auto it = upper_bound(nums.begin(), nums.end(), i)-nums.begin();
            long long st = 0, en = it-1,mid;
            while(st<=en){
                mid = (st+en)>>1;
                if((it-mid)*i-pre[it]+pre[mid]<=k){
                    ans = max(ans*1LL,it-mid);
                    en=mid-1;
                }else st = mid+1;
            }     
        }
        return ans;
    }
};