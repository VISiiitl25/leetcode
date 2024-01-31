class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        stack<int>s;
        for(int i=n-1;i>-1;i--){
           
            
                while(!s.empty()&& temperatures[i]>=temperatures[s.top()]){
                    s.pop();
                }
                 if(s.empty()){
                ans[i]=0;
               
            }
            else{
                ans[i]=s.top()-i;
            }
            s.push(i);
                
            
        }
        return ans;
    }
};