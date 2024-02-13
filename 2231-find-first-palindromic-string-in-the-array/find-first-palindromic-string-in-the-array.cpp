class Solution {
public:bool isPalindrome(string str) {
    int low = 0;
    int high = str.size() - 1;
 
    // Keep comparing characters while they are same
    while (low < high) {
        if (str[low] != str[high]) {
            return false; // not a palindrome.
        }
        low++; // move the low index forward
        high--; // move the high index backwards
    }
      return true; // is a palindrome     
}
    string firstPalindrome(vector<string>& words) {
        for(auto i:words){
            if(isPalindrome(i)){
                return i;
            }
        }
        return "";
    }
};