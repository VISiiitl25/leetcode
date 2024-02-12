class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int freq=1;
        int maj=nums[0];int n=nums.size();
        for(int i=1;i<nums.size();i++){
            if(freq==0){
                maj=nums[i];
            }
            else if(nums[i]==maj){
                freq++;
            }
            else{
                freq--;
                 if(freq==0){
                maj=nums[i];freq=1;
            }
            }
        }
        freq=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maj)freq++;
        }
         return maj;

        return -1;

        return 0;
    }
};