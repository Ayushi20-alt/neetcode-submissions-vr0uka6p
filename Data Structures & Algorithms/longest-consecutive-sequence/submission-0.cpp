class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int longest = 0;
        int count_curr = 0;
        int last_smaller = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] - 1 == last_smaller){
                count_curr++;
                last_smaller = nums[i];
            }else if (nums[i] == last_smaller){
                continue;
            }else{
                count_curr = 1;
                last_smaller = nums[i];
            }

            longest = max(longest , count_curr);
        }

        return longest;
    }
};
