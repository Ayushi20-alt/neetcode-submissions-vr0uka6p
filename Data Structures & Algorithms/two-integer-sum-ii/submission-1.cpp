class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>vec;
        int n = numbers.size();
        int st = 0, end = n-1;
        while(st < end){
            if(numbers[st] + numbers[end] > target){
                end--;
            }else if(numbers[st] + numbers[end] < target){
                st++;
            }else{
                vec.push_back(st + 1);
                vec.push_back(end + 1);
                return vec;
            }
        }
        return vec;
    }
};
