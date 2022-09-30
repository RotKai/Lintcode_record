class Solution {
public:
    /**
     * @param nums: a non-empty array only positive integers
     * @return: true if can partition or false
     */
    bool canPartition(vector<int> &nums) {
        // write your code here
        int sum = 0;
        for (auto num:nums){
            sum += num;
        }
        if (sum % 2 == 1) return false;
        int mid = sum /= 2;
        vector<int> dp(mid+1);
        dp[0] = 1;
        for (auto num:nums)
            for (int j=mid; j >= num; --j){
                dp[j] = dp[j] || dp[j-num];
            }
        return dp[mid];
    }
};
