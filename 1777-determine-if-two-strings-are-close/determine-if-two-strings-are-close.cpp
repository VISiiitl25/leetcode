class Solution {
public:
    bool closeStrings(string t1, string t2) {
        if (t1.size() != t2.size()) {
            return false; 
        }
        
        vector<int> count1(26, 0), count2(26, 0);
      
        for (char ch : t1) {
            count1[ch - 'a']++;
        }
        
       
        for (char ch : t2) {
            count2[ch - 'a']++;
        }
        
        for (int i = 0; i < 26; ++i) {
            if ((count1[i] == 0 && count2[i] != 0) || (count1[i] != 0 && count2[i] == 0)) {
                return false;
            }
        }
       
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());
        
      
        return count1 == count2;
    }
};
