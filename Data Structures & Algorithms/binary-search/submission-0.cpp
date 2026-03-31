class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = -1; int hi = nums.size();
        while(lo + 1 < hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] >= target){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        if(hi < nums.size() && nums[hi] == target) return hi;
        return -1;
    }
};
