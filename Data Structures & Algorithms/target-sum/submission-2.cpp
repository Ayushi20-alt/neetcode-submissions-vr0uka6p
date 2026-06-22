class Solution {
public:
    int numberofSubsets(int ind, int target, vector<int>&arr
	, vector<vector<int>> &dp) {
		// base case
		if (ind == 0) {
			if (target == 0 && arr[0] == 0)
				return 2;
			if (target == 0)
				return 1;
			if (target == arr[0])
				return 1;
			return 0;
		}
		
		if (dp[ind][target] != -1)
			return dp[ind][target];
		
		int not_pick = numberofSubsets(ind - 1, target, arr, dp);
		int pick = 0;
		if (arr[ind] <= target) pick = numberofSubsets(ind - 1, target - arr[ind],
		arr, dp);
		
		return dp[ind][target] = pick + not_pick;
		
	}
	int countPartitions(vector<int>& arr, int diff) {
		// Code here
		// s1 - s2 = d
		// totalsum = s1 + s2
		// totalsum -2s2 = d
		// s2 = totalsum - d /2;
		
		int sum = accumulate(arr.begin(), arr.end(), 0);
		
		if (sum - diff < 0)
			return 0;
		if ((sum - diff) % 2)
			return 0;
		
		int target = (sum - diff)/2;
		int n = arr.size();
		
		vector<vector<int>> dp(n, vector<int>(target + 1, -1));
		
		return numberofSubsets(n - 1, target, arr, dp);
	}
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target); 
    }
};
