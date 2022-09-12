class Solution {
public:
    /**
     * @param coins: a list of integer
     * @param amount: a total amount of money amount
     * @return: the fewest number of coins that you need to make up
     */

    int coinChange(vector<int> &coins, int amount) {
        // write your code here
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for (int i=1; i<=amount; ++i){
            for (int j=0; j< coins.size(); ++j){
                int cur_coin = coins[j];
                if (i-cur_coin >=0 && dp[i-cur_coin] != INT_MAX)
                    dp[i] = min (dp[i], dp[i-cur_coin]+1);
            }
        }
        return dp[amount]==INT_MAX? -1:dp[amount];
    }
};
