class Solution {
public:
    int mySqrt(int x) {
        int lo = -1; 
        int hi = long(x) + 1;

        while(lo + 1 < hi){
            int mid = lo + (hi - lo)/2;
            if(mid * mid <= x){
                lo = mid;
            }else{
                hi = mid;
            }
        }

        return lo;
    }
};