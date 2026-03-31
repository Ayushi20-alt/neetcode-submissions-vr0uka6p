class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>result;

        vector<vector<bool>>pacificVisited(m, vector<bool>(n, false));
        vector<vector<bool>>atlanticVisited(m, vector<bool>(n, false));

        for(int j = 0; j < n; j++){
            DFS(heights, 0, j, INT_MIN, pacificVisited); // top Row 
            DFS(heights, m-1, j, INT_MIN, atlanticVisited); // bottom Row
        }

        for(int i = 0; i < m; i++){
            DFS(heights, i, 0, INT_MIN, pacificVisited); // top Col
            DFS(heights, i, n-1, INT_MIN, atlanticVisited);
        }

        for(int i = 0; i< m; i++){
            for(int j = 0; j < n; j++){
                if(pacificVisited[i][j] && atlanticVisited[i][j]){
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void DFS(vector<vector<int>>& heights, int i, int j, int prevValue, 
    vector<vector<bool>>& visited){
        if(i < 0 || i >= heights.size() || j < 0 || j > heights[0].size()) return;
        if(heights[i][j] < prevValue || visited[i][j]) return;
        visited[i][j] = true;
        for(int k = 0; k < 4; k++){
            int r = i + directions[k][0];
            int c = j + directions[k][1];

            DFS(heights, r, c, heights[i][j], visited);
        }
    }
};
