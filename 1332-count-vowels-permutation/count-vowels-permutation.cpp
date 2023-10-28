class Solution {
public:
    map<string, int> mp;
    const int mod = pow(10, 9) + 7;

    long long recur(int i, int n, char lastc) {
        if (i == n) return 1;

        string x = to_string(i);
        x += '|';
        x += lastc;

        if (mp.find(x) != mp.end()) {
            return mp[x];
        }

        long long count = 0;
        if (i == 0) {
            count = (count + recur(i + 1, n, 'a')) % mod;
            count = (count + recur(i + 1, n, 'e')) % mod;
            count = (count + recur(i + 1, n, 'i')) % mod;
            count = (count + recur(i + 1, n, 'o')) % mod;
            count = (count + recur(i + 1, n, 'u')) % mod;
        } else {
            if (lastc == 'a') {
                count = (count + recur(i + 1, n, 'e')) % mod;
            } else if (lastc == 'e') {
                count = (count + recur(i + 1, n, 'a')) % mod;
                count = (count + recur(i + 1, n, 'i')) % mod;
            } else if (lastc == 'i') {
                count = (count + recur(i + 1, n, 'a')) % mod;
                count = (count + recur(i + 1, n, 'e')) % mod;
                count = (count + recur(i + 1, n, 'o')) % mod;
                count = (count + recur(i + 1, n, 'u')) % mod;
            } else if (lastc == 'o') {
                count = (count + recur(i + 1, n, 'i')) % mod;
                count = (count + recur(i + 1, n, 'u')) % mod;
            } else if (lastc == 'u') {
                count = (count + recur(i + 1, n, 'a')) % mod;
            }
        }

        mp[x] = count;
        return count;
    }

    int countVowelPermutation(int n) {
        int count = 0;

        count = (count + recur(0, n, 'a')) % mod;
        

        return count;
    }
};
