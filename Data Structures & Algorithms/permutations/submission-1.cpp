class Solution {
public:
    void getPerms(vector<int>& nums, int indx, vector<vector<int>>& ans, vector<int>&vec){
        if(indx == nums.size()){
            ans.push_back({vec});
            return;
        }

        for(int i = indx; i < vec.size(); i++){
            swap(vec[indx], vec[i]); // indx place -> ith value choice
            getPerms(vec, indx + 1, ans, vec);
            swap(vec[indx], vec[i]); // backtrack
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>vec = nums;
        getPerms(nums, 0, ans, vec);
        return ans;
    }
};
