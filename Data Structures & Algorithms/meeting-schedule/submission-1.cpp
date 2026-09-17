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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin() , intervals.end() , [](const auto& i , const auto& j){
            return i.end < j.end;
        });
        int end = intervals[0].end;
        for(int i = 1 ; i < intervals.size() ; i++){
            if(end > intervals[i].start) return false;
            else end = max(end , intervals[i].end);
        }
        return true;
    }
};
