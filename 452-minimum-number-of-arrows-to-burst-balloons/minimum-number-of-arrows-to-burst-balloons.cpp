class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
       int n=points.size();
       sort(points.begin(),points.end());
       int c=1;
        int first=points[0][0];
        int second=points[0][1];
        for(auto it:points){
            for(auto i:it){
                cout<<i<<" ";
            }cout<<endl;
        }
       for(int i=1;i<n;i++){

           if(points[i][0]<=second){
              first=min(first,points[i][0]);
              second=min(second,points[i][1]);
           }
           else{
               first=points[i][0];
               second=points[i][1];c++;
           }
       }
       return c;
    }
};