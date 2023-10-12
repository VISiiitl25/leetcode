/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

            int len=mountainArr.length();
            int l=0,h=len-1;

            int peak=-1;
            int pos=-1;

            while(l<=h){
                int mid=(l+h)/2;
                int x=mountainArr.get(mid);

                if(mid>0&& mid<len-1){
                    int y=mountainArr.get(mid-1);
                    int z=mountainArr.get(mid+1);
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
            //return peak;
            if(target==peak){
                return pos;
            }
            
            l=0,h=pos-1;
            while(l<=h){
                int mid=(l+h)/2;
                int x=mountainArr.get(mid);

                if(x==target){
                    return mid;
                }
                else if(x<target){
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
            l=pos+1,h=len-1;

            while(l<=h){
                 int mid=(l+h)/2;
                int x=mountainArr.get(mid);

                if(x==target){
                    return mid;
                }
                else if(x<target){
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            return -1;
    }
};