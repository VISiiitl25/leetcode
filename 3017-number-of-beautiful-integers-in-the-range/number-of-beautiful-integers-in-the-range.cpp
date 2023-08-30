class Solution {
public:
    
    int dp[12][2][12][12][2][22];

    int recur(int index, int tight, int even, int odd, int k, int n, int seen, string &a, int sum) {
        if (index == n) {
            if (even == odd && sum % k == 0 && seen == 1) {
                return 1;
            } else {
                return 0;
            }
        }
        if (dp[index][tight][even][odd][seen][sum] != -1) {
            return dp[index][tight][even][odd][seen][sum];
        }

        int ub = tight == 1 ? (a[index] - '0') : 9;
        int res = 0;

        for (int i = 0; i <= ub; i++) {
            int cs = sum;
            int cseen = seen;
            if (i > 0) {
                cseen = 1;
            }

            int req = n - 1 - index;
            int curr = i;
            for (int j = 0; j < req; j++) {
                curr = ((curr % k) * (10 % k)) % k;
            }
            int ns = (sum + curr) % k;
            int ne = even;
            int no = odd;

            if (i % 2 == 0) {
                if (i != 0) {
                    ne++;
                } else {
                    if (seen == 1) {
                        ne++;
                    }
                }
            } else {
                no++;
            }

            int nt = 0; // new tight
            if (tight == 1 && i == ub) {
                nt = 1;
            }

            res += recur(index + 1, nt, ne, no, k, n, cseen, a, ns);
        }
        return dp[index][tight][even][odd][seen][sum] = res;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        string a = to_string(high);
        memset(dp, -1, sizeof(dp));

        int ans1 = recur(0, 1, 0, 0, k, a.size(), 0, a, 0);

        string b = to_string(low - 1);
        memset(dp, -1, sizeof(dp));

        int ans2 = recur(0, 1, 0, 0, k, b.size(), 0, b, 0);

        int res = ans1 - ans2;
        return res;
    }
};
