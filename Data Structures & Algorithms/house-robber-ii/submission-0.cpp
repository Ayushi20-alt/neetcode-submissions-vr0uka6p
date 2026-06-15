class Solution {
public:
    int solve(int ind, vector<int>&nums, vector<int>&dp){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + solve(ind-2, nums, dp);
        int notPick = 0 + solve(ind-1, nums, dp);
        return dp[ind] =  max(pick, notPick);
    }
    int robLinear(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n - 1, nums, dp);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> first(nums.begin(), nums.end() - 1); // exclude last
        vector<int> second(nums.begin() + 1, nums.end()); // exclude first
        return max(robLinear(first), robLinear(second));
    }
};
