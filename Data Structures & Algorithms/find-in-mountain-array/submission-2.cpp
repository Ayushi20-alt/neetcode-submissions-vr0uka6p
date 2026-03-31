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

    int findPeak(MountainArray &arr){
        int n = arr.length();

        int lo = -1;        // invalid
        int hi = n - 1;     // valid

        while(lo + 1 < hi){
            int mid = lo + (hi - lo) / 2;

            if(arr.get(mid) > arr.get(mid + 1)){
                hi = mid;          // descending → valid
            }else{
                lo = mid;          // ascending → invalid
            }
        }

        return hi;
    }

    int searchAscending(MountainArray &arr, int hi, int target){
        int lo = -1;

        while(lo + 1 < hi){
            int mid = lo + (hi - lo) / 2;

            if(arr.get(mid) >= target){
                hi = mid;
            }else{
                lo = mid;
            }
        }

        if(arr.get(hi) == target) return hi;
        return -1;
    }

    int searchDescending(MountainArray &arr, int lo, int hi, int target){

        while(lo + 1 < hi){
            int mid = lo + (hi - lo) / 2;

            if(arr.get(mid) <= target){
                hi = mid;
            }else{
                lo = mid;
            }
        }

        if(arr.get(hi) == target) return hi;
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {

        int peak = findPeak(mountainArr);

        int left = searchAscending(mountainArr, peak, target);
        if(left != -1) return left;

        return searchDescending(
            mountainArr,
            peak,
            mountainArr.length() - 1,
            target
        );
    }
};