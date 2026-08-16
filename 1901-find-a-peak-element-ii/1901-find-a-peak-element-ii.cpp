class Solution {
private:
    // Helper function to find row index of max element in a given column
    int findMaxRow(vector<vector<int>>& mat,int n,int m,int col){
        int max_val=-1,max_row=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>max_val){
                max_val=mat[i][col];
                max_row=i;
            }
        }
        return max_row;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int low=0,high=m-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int max_row=findMaxRow(mat,n,m,mid);
            
            int left=mid-1>=0?mat[max_row][mid-1]:-1;
            int right=mid+1<m?mat[max_row][mid+1]:-1;
            
            // Peak condition check
            if(mat[max_row][mid]>left&&mat[max_row][mid]>right)
                return {max_row,mid};
            else if(mat[max_row][mid]<left)
                high=mid-1; // Search left columns
            else
                low=mid+1; // Search right columns
            
        }
        return {-1,-1};
    }
};