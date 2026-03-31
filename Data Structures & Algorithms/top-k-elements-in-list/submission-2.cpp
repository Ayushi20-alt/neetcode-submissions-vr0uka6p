class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int num : nums) {
            freq[num]++;
        }

        using pii = pair<int,int>; // {frequency, number}

        priority_queue<
            pii,
            vector<pii>,
            greater<pii>
        > pq;  // min heap

        for(auto it : freq) {
            pq.push({it.second, it.first});
            if(pq.size() > k) {
                pq.pop();  // remove smallest frequency
            }
        }

        vector<int>result;
        while(k--){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
