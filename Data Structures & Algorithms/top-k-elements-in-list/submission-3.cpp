class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        vector<vector<int>>bucket(n+1);
        // index = freq
        // value = elements
        // bucket[i] = elements having i frequency
        for(auto it : mpp){
            int ele = it.first;
            int freq = it.second;
            bucket[freq].push_back(ele);
        }

        vector<int>result;
        for(int i = bucket.size() - 1; i >= 0; i--){
            if(bucket[i].size() == 0) continue;

            while(k > 0 && bucket[i].size() > 0){
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }

        return result;
    }
};
