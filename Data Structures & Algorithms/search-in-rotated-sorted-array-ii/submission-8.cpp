class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = (int)nums.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            // Can't determine which half is sorted → shrink both ends
            if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) {
                lo++;
                hi--;
            }
            // Left half [lo..mid] is sorted
            else if (nums[lo] <= nums[mid]) {
                // Target lies within the sorted left half
                if (nums[lo] <= target && target <= nums[mid])
                    hi = mid;       // search left
                else
                    lo = mid + 1;   // search right
            }
            // Right half [mid..hi] is sorted
            else {
                // Target lies within the sorted right half
                if (nums[mid] < target && target <= nums[hi])
                    lo = mid + 1;   // search right
                else
                    hi = mid;       // search left
            }
        }

        return nums[lo] == target;
    }
};