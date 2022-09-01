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
    int minMeetingRooms(vector<Interval> &intervals) {
        priority_queue<int,vector<int>,greater<int>> q;
        sort (intervals.begin(),intervals.end(),[](Interval &a, Interval &b)->bool {
            if (a.start != b.start)
                return a.start < b.start;
            else 
                return a.end<b.end;
        });
        q.push(intervals[0].end);
        for (int i=1; i<intervals.size(); ++i){
            if (intervals[i].start >= q.top()){
                q.pop();
            }
            q.push(intervals[i].end);
        }
        return q.size();
    }
};
