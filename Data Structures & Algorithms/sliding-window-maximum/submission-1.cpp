class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>vec;

        for(int i = 0; i <= n - k; i++){
            int maxi = INT_MIN;
            for(int j = i; j < i + k; j++){
                maxi = max(maxi, nums[j]);
            }
            vec.push_back(maxi);
        }

        return vec;
    }
};
