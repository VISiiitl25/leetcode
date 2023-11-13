class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
    }
    
    string sortVowels(string s) {
        vector<char> vow;
        for (auto &i : s) if (isVowel(i)) vow.push_back(i);
        sort(vow.begin(), vow.end());
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vow[j++];
            }
        }
        return s;
    }
};