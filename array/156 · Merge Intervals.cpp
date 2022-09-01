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

private:
static bool cmp (const Interval &a, const Interval &b){
    if (a.start != b.start)
        return a.start < b.start;
    else
        return a.end < b.end;
}
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        if (intervals.empty()) return {};
        sort(intervals.begin(),intervals.end(),cmp);
        vector<Interval> ans;
        ans.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); ++i){
            auto cur = intervals[i];
            if (ans.back().end >= cur.start){
                ans.back().start = min(cur.start,ans.back().start);
                ans.back().end = max(cur.end,ans.back().end);
            }
            else{
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
