class Solution {
public:
    int solve(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if(ind == 0){
            return amount % coins[0] == 0;
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int not_take = 0 + solve(ind-1, amount, coins, dp);
        int take = 0;
        if(coins[ind] <= amount) take = solve(ind, amount - coins[ind], coins, dp);

        return dp[ind][amount] = not_take + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
        return solve(n-1, amount, coins, dp);
    }
};
