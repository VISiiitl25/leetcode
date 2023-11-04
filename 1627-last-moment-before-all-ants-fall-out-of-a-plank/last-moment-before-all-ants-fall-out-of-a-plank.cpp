class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxa=0;

        for(int i=0;i<left.size();i++){
            maxa=max(maxa,left[i]);
        }
        for(int i=0;i<right.size();i++){
            maxa=max(maxa,n-right[i]);
        }
        return maxa;
    }
};