class Solution {
public:
    int bestClosingTime(string customers) {
        
        int n=customers.size();

        int c1=0,c2=0;

        int y[n],N[n];

        
        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                c1++;
            
            }
            else{
                c2++;
            }
           
        }
        int mini=c1;
        int mi=mini;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                mi--;
               
            }
            else{
                mi++;
            }
             if(mi<mini){
                    mini=mi;
                    ind=i;
                }
        }
        return ind+1;


    }
};