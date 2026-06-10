class Solution {
public:
    void findCombinations(int ind, int target, vector<int> &arr, vector<int>& vec, 
        vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(vec);
            return;
        }

        for(int i = ind; i < arr.size(); i++){
            if(i > ind && arr[i] == arr[i-1])continue;
            if(arr[i] > target) break;
            vec.push_back(arr[i]);
            findCombinations(i + 1, target - arr[i], arr, vec, ans);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int> vec;
        findCombinations(0, target, candidates, vec, ans);
        return ans;
    }
};
