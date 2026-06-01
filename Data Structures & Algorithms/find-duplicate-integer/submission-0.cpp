class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int>mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(mpp.find(nums[i]) != mpp.end()){
                return nums[i];
            }
            mpp[nums[i]]++;
        }
        return -1;
    }
};
