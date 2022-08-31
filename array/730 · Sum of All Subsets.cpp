class Solution {
public:
    /**
     * @param n: the given number
     * @return: Sum of elements in subsets
     */
    int subSum(int n) {
        // write your code here
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        int size = 1;
        for (int i=2; i<n+1; ++i){
            dp[i] = dp[i-1] + (dp[i-1] + size * i)  + i ;
            size = size * 2 + 1;
        }
        return dp[n];
    }
};
