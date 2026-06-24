class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m-1;
        int left = 0, right = n-1;
        vector<int>ans;

        while(top <= bottom && left <= right){
            // right
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            // bottom
            for(int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            // left
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                   // ask row constant h ya col
                   ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right){
                // top
                for(int i = bottom; i >= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }    
        }

        return ans;    
    }
};
