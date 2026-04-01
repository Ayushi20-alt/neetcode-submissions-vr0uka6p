class Solution {
public:
    bool search(vector<int>& nums, int target) {
      // first find the pivot then search both left and right wise
        int miniIndex = findMin(nums);
        if(target <= nums[nums.size()-1]){
            return binarySearch(nums, target, miniIndex, nums.size()-1);
        }else{
            if(miniIndex == 0) return false; 
            return binarySearch(nums, target, 0, miniIndex-1);
        }
    }
int findMin(vector<int>&nums){
    int lo = -1;
    int hi = nums.size()-1;

    while(lo + 1 < hi){

        while(hi > 0 && nums[hi] == nums[hi-1]){
            hi--;
        }

        int mid = lo + (hi-lo)/2;

        if(nums[mid] <= nums[hi]){
            hi = mid;
        }else{
            lo = mid;
        }
    }

    return hi;
}


    int binarySearch(vector<int>&nums, int target, int left, int right){
        if(left > right) return false;

        int lo = left -1; int hi = right;
        while(lo + 1 < hi){
            int mid = lo + (hi - lo)/2;
            if(isGreaterOrEqual(nums[mid], target)){
                hi = mid;
            }else{
                lo = mid;
            }
        }

        return nums[hi] == target;
    }

    bool isGreaterOrEqual(int num, int target){
        return num >= target;
    }
};