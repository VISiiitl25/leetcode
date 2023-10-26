class RangeFreqQuery {
public:

unordered_map<int,vector<int>>mpp;
    RangeFreqQuery(vector<int>& arr) {

        for(int i = 0;i<arr.size();++i)
            mpp[arr[i]].push_back(i);
        
    }
    
    int query(int left, int right, int value) {
        
       int l = lower_bound(mpp[value].begin(),mpp[value].end(),left)-mpp[value].begin();
       int r = upper_bound(mpp[value].begin(),mpp[value].end(),right)-mpp[value].begin();
     
       return r-l;
    }
};