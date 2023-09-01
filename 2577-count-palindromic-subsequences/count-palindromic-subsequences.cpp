class Solution
{
public:
    int dp[10001][6][11][11];
    const int m=pow(10,9)+7;
    
    int recur(int i, int n, string &s, int cnt, int first, int second)
    {
        if (i == n)
        {
            return dp[i][cnt][first+1][second+1] = cnt == 5;
        }

        if (dp[i][cnt][first+1][second+1] != -1)
        {
            return dp[i][cnt][first+1][second+1]%m;
        }

        int x = recur(i + 1, n, s, cnt, first, second)%m;
        int y = 0;

        if (cnt == 4 && s[i] - '0' == first)
        {
            y = recur(i + 1, n, s, cnt + 1, first, second)%m;
        }

        if (cnt == 3 && s[i] - '0' == second)
        {
            y = recur(i + 1, n, s, cnt + 1, first, second)%m;
        }

        if (cnt == 2)
        {
            y = recur(i + 1, n, s, cnt + 1, first, second)%m;
        }

        if (cnt == 1)
        {
            y = recur(i + 1, n, s, cnt + 1, first, s[i] - '0')%m;
        }

        if (cnt == 0)
        {
            y = recur(i + 1, n, s, cnt + 1, s[i] - '0', second)%m;
        }

        return dp[i][cnt][first+1][second+1] = (x%m + y%m)%m;
    }

    int countPalindromes(string s)
    {
        memset(dp, -1, sizeof dp);
        return recur(0, s.size(), s, 0, -1, -1)%m;
    }
};
