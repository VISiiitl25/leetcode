
class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while (n > 0) {
            n--;  
            char c = 'A' + n % 26;
            ans = c + ans;
            n /= 26;
        }
        return ans;
    }
};
