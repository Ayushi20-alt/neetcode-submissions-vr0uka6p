/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int findPeak(MountainArray &mountainArr){
    int n = mountainArr.length();
    int lo = -1;
    int hi = n - 1;

    while(lo + 1 < hi){
        int mid = lo + (hi - lo) / 2;

        if(mountainArr.get(mid) > mountainArr.get(mid + 1)){
            hi = mid;      // valid
        } else {
            lo = mid;      // invalid
        }
    }
    return hi;
}

    int binarySearchAsc(MountainArray &mountainArr, int lo, int hi, int target){
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            int val = mountainArr.get(mid);

            if(val == target) return mid;
            if(val < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }

    int binarySearchDesc(MountainArray &mountainArr, int lo, int hi, int target){
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            int val = mountainArr.get(mid);

            if(val == target) return mid;
            if(val > target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {

        int peak = findPeak(mountainArr);

        int left = binarySearchAsc(mountainArr, 0, peak, target);
        if(left != -1) return left;

        return binarySearchDesc(mountainArr, peak + 1,
                                mountainArr.length() - 1,
                                target);
    }
};