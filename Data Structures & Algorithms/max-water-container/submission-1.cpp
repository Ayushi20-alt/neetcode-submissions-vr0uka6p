class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxWater = 0;
        int lp = 0, rp = n-1;
        while(lp < rp){
            int weight = rp - lp;
            int height = min(heights[lp], heights[rp]);
            int currWeight = weight * height;
            maxWater = max(maxWater, currWeight);

            heights[lp] < heights[rp] ? lp++ : rp--;
        }

        return maxWater;
    }
};
