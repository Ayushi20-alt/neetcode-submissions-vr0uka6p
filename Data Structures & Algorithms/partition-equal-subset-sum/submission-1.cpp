class Solution {
public:
    bool solve(int i, int target, vector<int>&nums, vector<vector<int>>&dp){
        int n = nums.size();
        if(target == 0) return true;
        if(i == n) return false;

        if(dp[i][target] != -1) return dp[i][target];

        bool notTake = 0 + solve(i+1, target, nums, dp);
        bool take = false;
        if(nums[i] <= target){
            take = solve(i+1, target-nums[i], nums, dp);
        }
        return dp[i][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int target = sum/2;
        int n = nums.size();

        vector<vector<int>>dp(n, vector<int>(target+1, -1));

        return solve(0, target, nums, dp);
    }
};
