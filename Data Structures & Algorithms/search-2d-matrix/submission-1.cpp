class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int lo = -1;
        int hi = m * n;

        while (lo + 1 < hi) {

            int mid = lo + (hi - lo) / 2;

            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] >= target) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        if (hi == m * n) return false;  // u didnt find the element

        int row = hi / n;
        int col = hi % n;

        return matrix[row][col] == target;
    }
};
