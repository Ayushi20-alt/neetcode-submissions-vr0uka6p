class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>st;

        for(int i = 0; i < n; i++){
            int target = -nums[i];
            set<int>s;
            for(int j = i+1; j < n; j++){
                if(s.find(target - nums[j]) != s.end()){
                    vector<int>vec = {nums[i], nums[j], target - nums[j]};
                    sort(vec.begin(), vec.end());
                    st.insert(vec);
                }
                s.insert(nums[j]);
            }
        }

        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};
