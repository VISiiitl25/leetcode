class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        int i=0;int last=0;
        vector<vector<int>>ans;
        int n=nums.size();
        while(i<n){
            if(temp.size()==0){
                last=nums[i];
                temp.push_back(nums[i]);
            }
            else{
                if(nums[i]-last<=k){
                    temp.push_back(nums[i]);
                }
                else{
                    return {};
                }
                if(temp.size()==3){
                    ans.push_back(temp);
                    temp.clear();
                }
            
            }i++;
        }
        return ans;
    }
};