class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 0;
        int hi = *max_element(piles.begin(), piles.end());

        while(lo + 1 < hi){
            int mid = lo + (hi-lo)/2;
            if(canFinishInHHours(piles, h, mid)){
                hi = mid;
            }else{
                lo = mid;
            }
        }

        return hi;
    }

    bool canFinishInHHours(vector<int>& piles, int h, int speed){
        int time = 0;
        for(int i = 0; i < piles.size(); i++){
            time += (piles[i] + speed - 1) / speed; // ceil(piles[i] / speed)
            if(time > h) return false;
        }

        return true;
    }
};
