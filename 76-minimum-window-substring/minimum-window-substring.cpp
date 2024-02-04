class Solution {
public:
    string minWindow(string s, string t) {
    unordered_map<char, int> charCount;
    for (char c : t) {
        charCount[c]++;
    }

    int left = 0, right = 0, minLength = INT_MAX, minLeft = 0, count = t.length();

    while (right < s.length()) {
        if (charCount[s[right++]]-- > 0) {
            count--;
        }

        while (count == 0) {
            if (right - left < minLength) {
                minLength = right - left;
                minLeft = left;
            }

            if (charCount[s[left++]]++ == 0) {
                count++;
            }
        }
    }

    return (minLength == INT_MAX) ? "" : s.substr(minLeft, minLength);
}
};