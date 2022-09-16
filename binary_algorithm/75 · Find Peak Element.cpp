class Solution {
public:
    /**
     * @param a: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> &a) {
        // write your code here
        // if decreasing, peak is in left part
        int l = 1, r = a.size()-2;
        while(l < r){
            int mid = l + (r-l)/2;
            if(a[mid] > a[mid+1] && a[mid] > a[mid-1]) return mid;
            else if( a[mid] < a[mid-1] ) r = mid;
            else if ( a[mid] < a[mid+1]) l = mid + 1;
            else return mid;
        }
        return l;
    }
};
