class Solution {
public:
    /**
     * @param a: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &a) {
        // write your code here
        vector<bool> dp(a.size(),0);
        dp[0]=true;
        int n = a.size();
        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (dp[j])
                    dp[i] = i-j <= a[j] ? true:false;
                if (dp[i]==true)
                    break;
            }
        }
        return dp[n-1];
    }
};
