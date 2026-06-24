class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose the matrix and reverse every row
        // O(N/2) * O(N/2)
        int n = matrix.size();
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }

        // O(N * N/2)
        for(int i = 0; i < n; i++){
            // reverse every row
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
