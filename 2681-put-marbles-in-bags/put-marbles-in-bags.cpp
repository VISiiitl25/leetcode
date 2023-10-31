class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long>r;
        int n=weights.size();
        for(int i=0; i<n-1; i++) {
    r.push_back(weights[i] + weights[i+1]);
}

        sort(r.begin(),r.end());
        long long x1=weights[0]+weights[n-1];
        long long x2=x1;
        for(int i=0;i<k-1;i++){
            x1+=r[i];
        }
        reverse(r.begin(),r.end());
        for(int i=0;i<k-1;i++){
            x2+=r[i];
        }
        return x2-x1;
    }
};