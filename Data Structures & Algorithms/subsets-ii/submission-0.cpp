class Solution {
public:
    void findPerms(int indx, vector<int>& nums, vector<int>& vec, vector<vector<int>>&ans){
        if(indx == nums.size()){
            ans.push_back(vec);
            return;
        }

        vec.push_back(nums[indx]);
        findPerms(indx+1, nums, vec, ans);
        vec.pop_back();
        
        int i = indx + 1;
        while(i < nums.size() && nums[i] == nums[i-1]){
            i++;
        }
        findPerms(i, nums, vec, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>vec;
        findPerms(0, nums, vec, ans);
        return ans;
    }
};
