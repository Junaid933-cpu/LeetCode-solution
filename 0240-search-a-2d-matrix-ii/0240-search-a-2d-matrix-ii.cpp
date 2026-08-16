class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int row=0,col=n-1; // Start from top-right corner
        
        while(row<m&&col>=0){
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]>target)
                col--; // Target is smaller, eliminate rightmost column
            else
                row++; // Target is larger, eliminate top row
        }
        return false;
    }
};