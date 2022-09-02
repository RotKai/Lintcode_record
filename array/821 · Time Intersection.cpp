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
    /**
     * @param seqA: the list of intervals
     * @param seqB: the list of intervals
     * @return: the time periods
     */
    vector<Interval> timeIntersection(vector<Interval> &a, vector<Interval> &b) {
        // Write your code here
        vector<Interval> ans;
        if (a.empty() || b.empty()) return ans;
        int right = 0; int n = a.size();
        int left = 0; int m = b.size();
        while (right < n && left < m){
            int start_max = max(a[right].start, b[left].start);
            int end_min = min(a[right].end, b[left].end);
            if (start_max <= end_min){
                ans.push_back(Interval(start_max,end_min));
            }
            if (a[right].end > b[left].end) left++;
            else right++;
        }
        return ans;

    }
};
