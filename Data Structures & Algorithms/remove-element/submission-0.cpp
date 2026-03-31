class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(nums.at(i) == val){
                swap(nums.at(i), nums.at(size-1));
                --i;
                --size;
            }
        }
        return size;
    }
};