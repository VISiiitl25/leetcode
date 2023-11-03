class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        vector<int> diff;
        for (int i = 1; i < target.size(); i++) {
            diff.push_back(target[i] - target[i - 1]);
        }
        for (int i = 1; i < target[0]; i++) {
                ans.push_back("Push");
                ans.push_back("Pop");
        }
        ans.push_back("Push");
        for (int i = 0; i < diff.size(); i++) {
            int x = diff[i];
            for (int j = 0; j < x - 1; j++) {
                    ans.push_back("Push");
                    ans.push_back("Pop");                    
                }
                ans.push_back("Push");
        }
        
        return ans;
    }
};
