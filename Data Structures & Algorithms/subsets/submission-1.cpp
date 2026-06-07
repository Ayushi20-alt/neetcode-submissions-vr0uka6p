class Solution {
public:
    void printSubsets(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int i){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        // include
        temp.push_back(nums[i]);
        printSubsets(nums, temp, ans, i+1);

        temp.pop_back(); // backtrack
        // exclude
        printSubsets(nums, temp, ans, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> temp;
        printSubsets(nums, temp, ans, 0);
        return ans;
    }
};
