class Solution {
public:
    void findCombination(int ind, int target, vector<int>& nums, vector<vector<int>>& ans,
    vector<int>& ds){
        if(ind == nums.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        // pick the element
        if(nums[ind] <= target){
            ds.push_back(nums[ind]);
            findCombination(ind, target - nums[ind], nums, ans, ds);
            ds.pop_back();
        }
        findCombination(ind + 1, target, nums, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0, target, nums, ans, ds);
        return ans;
    }
};
