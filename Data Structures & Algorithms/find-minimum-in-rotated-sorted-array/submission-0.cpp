class Solution {
public:
    int findMin(vector<int> &nums) {
        int lo = -1;
        int hi = nums.size()-1;

        while(lo + 1 < hi){
            int mid = lo + (hi-lo)/2;
            if(isOnRight(nums, mid)){
                hi = mid;
            }else{
                lo = mid;
            }
        }

        return nums[hi];
    }

    bool isOnRight(vector<int>&nums, int mid){
        return nums[mid] <= nums[nums.size() - 1];
    }
};
