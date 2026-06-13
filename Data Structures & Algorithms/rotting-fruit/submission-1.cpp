class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // multisource dfs 
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int time = 0;

        queue<pair<int, int>>q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) {
                    fresh++;
                }
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(fresh>0 && !q.empty()){
            int length = q.size();
            for(int i = 0; i < length; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nrow = r + delrow[i];
                    int ncol = c + delcol[i];

                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        fresh--;
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
