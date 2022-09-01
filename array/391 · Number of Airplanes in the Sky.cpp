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
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        if (airplanes.size()<1) return 0;
        priority_queue<int,vector<int>,greater<int>> q;
        sort (airplanes.begin(),airplanes.end(),[](Interval &a, Interval &b)->bool {
            if (a.start != b.start)
                return a.start < b.start;
            else 
                return a.end<b.end;
        });
        q.push(airplanes[0].end);
        for (int i=1; i<airplanes.size(); ++i){
            if (airplanes[i].start >= q.top()){
                q.pop();
            }
            q.push(airplanes[i].end);
        }
        return q.size();
        
    }
};
