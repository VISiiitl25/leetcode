class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue <int, vector<int>, greater<int> > pq; 
        int last=0;
        for(int i=1;i<n;i++){
            if(heights[i]>heights[i-1]){
                if(ladders>0){
                    cout<<i<<" "<<heights[i]<<endl;
                    ladders--;
                    pq.push(heights[i]-heights[i-1]);
                    last=i;
                }
                else{
                    if(bricks<0){
                        return last;
                    }
                    else{
                        pq.push(heights[i]-heights[i-1]);
                        int lst=pq.top();
                        pq.pop();
                       
                        if(lst>bricks){
                            return last;
                        }
                        bricks-=lst;
                        
                        last=i;
                    }
                }
            }else{
                last=i;
            }
        }
        return last;
    }
};