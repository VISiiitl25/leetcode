class Solution {
public:
    

    int recur(int i, int n, vector<string>& arr, vector<string>& temp) {
        if (i == n) return 0;
        temp.push_back(arr[i]);
        map<int,int> mp;
        bool flag = true;
        for (auto ind : temp) {
            for (auto c : ind) {
                if (mp[c] > 0) {
                    flag = false;
                    break;
                } else {
                    mp[c]++;
                }
            }
        }
        int x = 0, y = 0;
        if (flag) x = arr[i].size() + recur(i + 1, n, arr, temp);
        temp.pop_back();
        y = recur(i + 1, n, arr, temp);
        return max(x, y);
    }

    int maxLength(vector<string>& arr) {
        vector<string> temp;
        return recur(0, arr.size(), arr, temp);
        ;
    }
};
