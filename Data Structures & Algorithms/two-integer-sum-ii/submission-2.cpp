class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int>mpp;
        vector<int>vec;
        int n = numbers.size();
        for(int i = 0; i < n;i++){
            int first = numbers[i];
            int second = target - first;
            if(mpp.find(second) != mpp.end()){
                vec.push_back(mpp[second] + 1);
                vec.push_back(i + 1);
                return vec;
            }
            mpp[first] = i;
        }

        return vec;
    }
};
