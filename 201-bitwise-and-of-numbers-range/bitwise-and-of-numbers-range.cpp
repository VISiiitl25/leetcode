class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==0)return 0;
        long long x=log2(left);
        long long y=log2(right);
        int ans=left;
        if(left==right)return left;
        if(x==y){
            for(long long i=left+1;i<=right;i++){
                ans=ans&i;
            }
        }
        return x==y?ans:0;
    }
};