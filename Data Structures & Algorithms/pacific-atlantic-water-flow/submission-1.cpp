class Solution {
public:
    void dfs(vector<vector<int>>& heights, int i, int j, int prevCelVal,
    vector<vector<bool>>& visited){
        if(i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()){
            return;
        }
        if(heights[i][j] < prevCelVal || visited[i][j]) return;
        visited[i][j] = true;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int k = 0; k < 4; k++){
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];
            dfs(heights, nrow, ncol, heights[i][j], visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>>result;
        vector<vector<bool>>pac(m, vector<bool>(n, false));
        vector<vector<bool>>atl(m, vector<bool>(n, false));

        // Top row and Bottom Row
        // Top row :- pacific connected already
        // Bottom row :- atlantic connected already
        for(int j= 0; j < n; j++){
            dfs(heights, 0, j, INT_MIN, pac);
            dfs(heights, m-1, j, INT_MIN, atl);
        }

        // first col & last col
        // first col :- pacific connected already
        // last col :- atlantic connected already
        for(int i = 0; i < m; i++){
            dfs(heights, i, 0, INT_MIN, pac);
            dfs(heights, i, n-1, INT_MIN, atl);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pac[i][j] && atl[i][j]){
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
