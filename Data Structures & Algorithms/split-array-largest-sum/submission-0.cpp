class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        long long lo = *max_element(nums.begin(), nums.end()) - 1; // invalid
        long long hi = accumulate(nums.begin(), nums.end(), 0LL);  // valid

        while(lo + 1 < hi){
            long long mid = lo + (hi - lo) / 2;

            if(canSplit(nums, k, mid)){
                hi = mid;
            }else{
                lo = mid;
            }
        }

        return hi;
    }

     bool canSplit(vector<int>& nums, int k, long long maxSum){
        long long sum = 0;
        int subarrays = 1;

        for(int num : nums){
            if(sum + num > maxSum){
                subarrays++;
                sum = num;
            }else{
                sum += num;
            }
        }

        return subarrays <= k;
    }
};