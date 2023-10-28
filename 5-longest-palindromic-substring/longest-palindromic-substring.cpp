class Solution {
public:
    string longestPalindrome(string str) {
        string pal = "";
        for (int i = 0; i < str.length(); ++i) {
            int l, r;
            l = r = i; 
            string found = findPalindrome(str, l, r);
            if (pal.length() < found.length()) {
                pal = found;
            }
            l = i;
            r = i + 1;
            found = findPalindrome(str, l, r);
            if (pal.length() < found.length()) {
                pal = found;
            }
        }
        return pal;
    }

    string findPalindrome(string s, int l, int r) {
        int ls = s.length();
        while (l >= 0 && r < ls && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
};
