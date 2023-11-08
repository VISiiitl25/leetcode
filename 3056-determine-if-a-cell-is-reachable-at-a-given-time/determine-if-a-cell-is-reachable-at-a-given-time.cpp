class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diff=abs(fx-sx);
        int di=abs(fy-sy);
        int mini=max(diff,di);
       
        if(mini==0){
            if(t==1){
                return 0;
            }
            return 1;
        }
        if(t>=mini)return true;

        return false;
    }
};