/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int>mpp; // events, delta
        int n = intervals.size();

        for(int i = 0; i < n; i++){
            mpp[intervals[i].start]++;
            mpp[intervals[i].end]--;
        }

        int overlaps = 0;
        int maxOverlaps = 0;

        for(auto &it : mpp){
            overlaps += it.second;
            maxOverlaps = max(maxOverlaps, overlaps);
        }

        return maxOverlaps;
    }
};
