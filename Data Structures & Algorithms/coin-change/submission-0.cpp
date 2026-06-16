class Solution {
public:
    int solve(int ind , int target, vector<int>&coins){
        if(ind == 0){
            if(target % coins[0] == 0) return target/coins[0];
            else return 1e9;
        }

        int notTake = 0 + solve(ind-1, target, coins);
        int take = INT_MAX;
        if(coins[ind] <= target) take = 1 + solve(ind , target - coins[ind], coins);

        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = solve(n-1, amount, coins);
        if(ans >= 1e9) return -1;
        return ans;
    }
};
