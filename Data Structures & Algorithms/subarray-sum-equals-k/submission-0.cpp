class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // element, count
        map<int, int> mpp;
        mpp[0] = 1;

        int count = 0;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            int el = sum - k;

            if(mpp.find(el) != mpp.end()){
                count += mpp[el];
            }

            mpp[sum]++;
        }

        return count;
    }
};