class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        while(i<m&&j<n){
            if(nums1[i]<nums2[j]){
                nums1.push_back(nums1[i]);i++;
            }
            else if(nums1[i]>nums2[j]){
                nums1.push_back(nums2[j]);j++;
            }
            else{
                nums1.push_back(nums1[i]);i++;
                nums1.push_back(nums2[j]);j++;
            }
        }
        for(int a=i;a<m;a++){
            nums1.push_back(nums1[a]);
        }
        for(int b=j;b<n;b++){
            nums1.push_back(nums2[b]);
        }
        // cout<<nums1.size()<<endl;
        nums1.erase(nums1.begin(),nums1.begin()+m+n);
    }
};