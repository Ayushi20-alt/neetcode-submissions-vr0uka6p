class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWater = 0;
        int n = heights.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int height = min(heights[i], heights[j]);
                int width = j - i;
                int ans = height * width;
                maxWater = max(ans, maxWater);
            }
        }

        return maxWater;
    }
};
