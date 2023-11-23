class Solution {
public:
    bool are_elements_in_ap(const multiset<int>& input_multiset) {
        vector<int> sorted_vector(input_multiset.begin(), input_multiset.end());
        sort(sorted_vector.begin(), sorted_vector.end());

        int d = sorted_vector[1] - sorted_vector[0];

        for (size_t i = 1; i < sorted_vector.size() - 1; ++i) {
            if (sorted_vector[i + 1] - sorted_vector[i] != d) {
                return false;
            }
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int n = l.size();

        for (int i = 0; i < n; ++i) {
            int a = l[i], b = r[i];
            multiset<int> m(nums.begin() + a, nums.begin() + b + 1);

            if (m.size() <= 1) {
                ans.push_back(false);
            } else {
                bool c = are_elements_in_ap(m);
                ans.push_back(c);
            }
        }

        return ans;
    }
};
