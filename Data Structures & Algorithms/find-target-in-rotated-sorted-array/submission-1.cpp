class Solution {
public:
    int search(vector<int>& nums, int target) {
        // first find the pivot then search both left and right wise
        int miniIndex = findMin(nums);
        if(target <= nums[nums.size()-1]){
            return binarySearch(nums, target, miniIndex, nums.size()-1);
        }else{
            return binarySearch(nums, target, 0, miniIndex-1);
        }
        return -1;
    }

    int findMin(vector<int>&nums){
        int lo = -1;
        int hi = nums.size();
        while(lo + 1 < hi){
            int mid = lo + (hi-lo)/2;
            if(isOnRight(nums, mid)){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        return hi;
    }

    bool isOnRight(vector<int>&nums, int mid){
        return nums[mid] <= nums[nums.size() - 1];
    }

    int binarySearch(vector<int>&nums, int target, int left, int right){
        if(left > right) return -1;
        int lo = left -1; int hi = right;
        while(lo + 1 < hi){
            int mid = lo + (hi - lo)/2;
            if(isGreaterOrEqual(nums[mid], target)){
                hi = mid;
            }else{
                lo = mid;
            }
        }

        return nums[hi] == target ? hi : -1;
    }

    bool isGreaterOrEqual(int num, int target){
        return num >= target;
    }
};
