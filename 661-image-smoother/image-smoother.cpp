class Solution {
public:
    
    pair<int,int> getSumAndCount(int row , int col , int n , int m , vector<vector<int>>&mat)
    {   
        int totalSum = 0;
        int count = 0;

        int delRow[8] = { -1 , -1 , 0 , 1 , 1 , 1 , 0 , -1};
        int delCol[8] = { 0 , 1 , 1 , 1 , 0 , -1 , -1 , -1 };

        for( int i = 0; i < 8 ; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if( nrow < n && nrow >=0 && ncol < m && ncol >=0 )
            {
                totalSum += mat[nrow][ncol];
                count += 1;
            }
        }

        return { totalSum , count};
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int n = img.size();
        int m = img[0].size();

        vector<vector<int>>ansMatrix( n , vector<int>( m , 0));

        for( int row = 0 ; row < n ; row++)
        {
            for( int col = 0 ; col < m ; col++)
            {
                 pair<int,int>it = getSumAndCount( row , col , n , m , img);

                 int sum = it.first + img[row][col];
                 int count = it.second + 1;
                
                 ansMatrix[row][col] = sum / count;
                 
            }
        }

        return ansMatrix;
    }
};