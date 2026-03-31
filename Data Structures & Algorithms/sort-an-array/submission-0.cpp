class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Counting Sort O(n+k) use only jab aapka input jab ek 
        // particular range ka ho shorter.
        unordered_map<int, int>mpp;
        for(int &num: nums){
            mpp[num]++;
        }

        int minE = *min_element(begin(nums), end(nums));
        int maxE = *max_element(begin(nums), end(nums));

        int k = 0;

        for(int i = minE; i <= maxE; i++){
            while(mpp[i] > 0) {
                nums[k] = i;
                k++;
                mpp[i]--;
            }
        }

        return nums;
    }
};