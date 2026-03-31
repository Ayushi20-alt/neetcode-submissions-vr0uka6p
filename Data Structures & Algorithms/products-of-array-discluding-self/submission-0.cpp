class Solution {

// Zeros	Output Behavior
// 0	Normal division
// 1	Only zero index gets product
// 2+	All outputs = 0

public:
vector<int> productExceptSelf(vector<int>& nums) {
    int totalProduct = 1;
    int zeroCount = 0;
                            
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
          zeroCount++;
        }else{
          totalProduct *= nums[i];
        }
     }
    vector<int> ans(nums.size(), 0);

    for(int i = 0; i < nums.size(); i++){
        if(zeroCount > 1) {
          ans[i] = 0;           
        }else if(zeroCount == 1) ans[i] = (nums[i] == 0) ? totalProduct : 0;
        else ans[i] = totalProduct / nums[i];
    }

    return ans;
}
};
