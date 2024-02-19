class Solution {
public:
    bool isPowerOfTwo(int n) {
        int x=__builtin_popcount(n);
        return x==1&& n>=1;
    }
};