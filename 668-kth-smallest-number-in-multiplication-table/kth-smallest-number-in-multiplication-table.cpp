class Solution {
public:
    int check(int m, int n, int mid) {
    int c = 0;
    for (int i = 1; i <= m; i++) {
       
        c += min(mid / i, n);
    }
    return c;
}

    int findKthNumber(int m, int n, int k) {

        int l=1, h=9e8;
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            int x=check(m,n,mid);

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