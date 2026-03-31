class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
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
                    q.emplace(i, j);
                }
            }
        }

        while(fresh>0 && !q.empty()){
            int length = q.size();

            for(int i = 0; i < length; i++){
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                for(int j =0; j < 4; j++){
                   int x = r + directions[j][0];
                   int y = c + directions[j][1];

                   if(x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1){
                    grid[x][y] = 2;
                    q.emplace(x, y);
                    fresh--;
                   }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
