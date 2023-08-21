class Solution {
public:
    void sortColors(vector<int>& arr) {
        int l=0,mid=0,h=arr.size()-1;
        while(mid<=h){
            if(arr[mid]==0){
                swap(arr[mid],arr[l]);
                l++;mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid],arr[h]);
                    h--;
                }
            }
        }
    
};