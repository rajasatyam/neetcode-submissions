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
        int n = intervals.size();
        if(n == 0) return 0;
        sort(intervals.begin() , intervals.end() , [](const auto& i , const auto& j){
            return i.start < j.start;
        });
        int ans = 0 , len = 0;
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i = 0 ; i < n ; i++){
            while(!pq.empty() && pq.top() <= intervals[i].start){
                len--;
                pq.pop();
            }
            len++;
            pq.push(intervals[i].end);
            ans = max(ans , len);
        }
        return ans;
    }
};