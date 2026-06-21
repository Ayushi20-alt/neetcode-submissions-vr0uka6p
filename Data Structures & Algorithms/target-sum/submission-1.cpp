class Solution {
public:
    int solve(int ind, int target, vector<int>&nums){
        // base case
        if(ind == nums.size()){
            return target == 0;
        }

        int neg = solve(ind+1, target - nums[ind], nums);
        int pos = solve(ind+1, target + nums[ind], nums);
        return neg + pos;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, target, nums);
    }
};
