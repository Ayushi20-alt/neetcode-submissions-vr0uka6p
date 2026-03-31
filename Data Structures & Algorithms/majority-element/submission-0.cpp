class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0];
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == element) count++;
            else if(count < 0){
                count = 0;
                element = nums[i];
            }else count --;
        }
        return element;
    }
};