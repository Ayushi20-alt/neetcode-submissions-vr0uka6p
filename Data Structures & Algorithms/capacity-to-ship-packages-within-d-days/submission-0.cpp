class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end()) - 1;
        int hi = accumulate(weights.begin(), weights.end(), 0);

        while(lo + 1 < hi){
            int mid = lo + (hi - lo)/2;
            if(canShipInGivenDays(weights, days, mid)){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        return hi;
    }

    bool canShipInGivenDays(vector<int>&weights, int days, int capacity){
        int requiredDays = 1;
        int currentLoad = 0;
        for (int w : weights) {
            if (currentLoad + w > capacity) {
                requiredDays++;
                currentLoad = 0;
            }

            currentLoad += w;
        }

        return requiredDays <= days;
    }
};