class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>mpp;
        vector<int>ans;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        for(auto it : mpp){
            if(it.second >= k){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
