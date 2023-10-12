class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
            int len=arr.size();
            int l=0,h=len-1;

            int peak=-1;
            int pos=-1;

            while(l<=h){
                int mid=(l+h)/2;
                int x=arr[mid];

                if(mid>0&& mid<len-1){
                    int y=arr[mid-1];
                    int z=arr[mid+1];
                    if(y<x && x>z){
                        peak=x;
                        pos=mid;
                        break;
                    }
                    else if(y<x &&x<z){
                        l=mid+1;
                    }
                    else{
                        h=mid-1;
                    }
                }
                else if(mid==0){
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }

            }
            return pos;
           
    }
};