class Solution {
public:
    int mySqrt(int x) {
        long lo = -1; 
        long hi = long(x) + 1;

        while(lo + 1 < hi){
            long mid = lo + (hi - lo)/2;
            if(mid * mid <= x){
                lo = mid;
            }else{
                hi = mid;
            }
        }

        return lo;
    }
};