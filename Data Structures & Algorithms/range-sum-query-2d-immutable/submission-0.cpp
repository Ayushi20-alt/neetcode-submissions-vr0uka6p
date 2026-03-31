class NumMatrix {
private:
    vector<vector<int>>rowPrefix;    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        rowPrefix = matrix;

        // building row wise prefix sum
        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                rowPrefix[i][j] += rowPrefix[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;

        for(int row = row1; row <= row2; row++){
            if(col1 == 0){
                sum += rowPrefix[row][col2];
            }else{
                sum += rowPrefix[row][col2] - rowPrefix[row][col1-1];
            }
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */