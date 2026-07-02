class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // j explores every element.
        // i always marks the end of the unique portion of the array.
        int i = 0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }

        return i+1;
    }
};