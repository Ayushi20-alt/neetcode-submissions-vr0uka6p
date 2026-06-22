class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 1; // current element to add hoga hi 

        if(dp[i][j] != -1) return dp[i][j];

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int k = 0; k < 4; k++){
            int r = i + delrow[k];
            int c = j + delcol[k];

            if(r >= 0 && r < m && c >= 0 && c < n && matrix[i][j] < matrix[r][c]){
                ans = max(ans, 1 + dfs(r, c, matrix, dp));
            }
        }

        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;

        vector<vector<int>>dp(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dfs(i, j, matrix, dp));
            }
        }

        return ans;
    }
};
