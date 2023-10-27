class Solution {
public:
    bool isSubsequence(string& s1, string& s2) {
        int n = s1.length(), m = s2.length();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s1[i] == s2[j])
                i++;
            j++;
        }
        return i == n;
    }

    bool check(string s, string p, int mid, vector<int>& removable) {
        map<int, int> mp;
        for (int i = 0; i < mid; i++) {
            mp[removable[i]] = 1;
        }
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(i) == mp.end()) {
                temp += s[i];
            }
        }
        return isSubsequence(p,temp);
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0, h = removable.size();
        int ans = 0;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (check(s, p, mid, removable)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};
