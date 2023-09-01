
class Solution {
public:
    long countOperationsToEmptyArray(vector<int>& A) {
        map<int, int> positions;
        int n = A.size();
        long ans= 0;

        for (int i = 0; i < n; ++i) {
            positions[A[i]] = i;
        }

        sort(A.begin(), A.end());

        for (int i = 1; i < n; ++i) {
            if (positions[A[i]] < positions[A[i - 1]]) {
                ans += n - i;
            }
        }

        return n+ans;
    }
};
