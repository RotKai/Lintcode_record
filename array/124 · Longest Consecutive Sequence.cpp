class Solution {
public:
    /**
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &nums) {
        // write your code here
        sort(nums.begin(),nums.end());
        int res = 1;
        int tmp = 1;
        for (int i=1; i<nums.size();++i){
            if (nums[i-1] == nums[i]){
                continue;
            }
            else if (nums[i-1] != nums[i]-1){
                tmp = 1;
            }
            else if (nums[i-1] == nums[i]-1){
                tmp ++;
            }
            res = max(res,tmp);
        }
        
        return res;
    }
};
