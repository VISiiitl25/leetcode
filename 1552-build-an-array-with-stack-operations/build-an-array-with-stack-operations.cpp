class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        vector<int> diff;

        for (int i = 1; i < target.size(); i++) {
            diff.push_back(target[i] - target[i - 1]);
        }

        if (target[0] != 1) {
            for (int i = 1; i < target[0]; i++) {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        } 
            ans.push_back("Push");
            
        

        for (int i = 0; i < diff.size(); i++) {
            int x = diff[i];
            
            if (x == 1) {
                ans.push_back("Push");
            } else {
                for (int j = 0; j < x - 1; j++) {
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    
                }
                ans.push_back("Push");
            }
        }
        return ans;
    }
};
