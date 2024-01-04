#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        

        std::priority_queue<int> pq;
        int count = 0;

        for (const auto& entry : mp) {
            int frequency = entry.second;
            if(frequency==1){
                return -1;
            }
            
            int x=frequency/3;
            int rem=frequency-3*x;
            
            if(rem==0){
                count+=x;
            }
            else{
                count+=x+1;}
                    
            
            
            
        }
        
        

       

        return count;
    }}
;
