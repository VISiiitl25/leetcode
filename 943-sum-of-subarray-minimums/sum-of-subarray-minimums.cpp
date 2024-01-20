class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                left[i] = -1;
            } else {
                left[i] = st.top();
            }
            st.push(i);
        }
        stack<int>().swap(st); 
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                right[i] = n;
            } else {
                right[i] = st.top();
            }
            st.push(i);
        }
for(auto i:left){
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i:right){
            cout<<i<<" ";
        }
        cout<<endl;
        
        int MOD = 1e9 + 7;
        long long result = 0;
       
        for (int i = 0; i < n; i++) {
            result = (result + (long long)arr[i] * (i - left[i]) * (right[i] - i)) % MOD;
        }

        return result;
    }
};
