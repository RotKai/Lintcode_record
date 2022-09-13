class Solution {
public:
    /**
     * @param nums: an array containing n + 1 integers which is between 1 and n
     * @return: the duplicate one
     */
    int findDuplicate(vector<int> &nums) {
        // write your code here
        int left = 0;
        int right = nums.size()-1;
        
        while (left < right){
            int mid = (left+right) / 2;
            int count = 0;
            for (auto num:nums){
                if (num <= mid){
                    count ++;
                }
            }
            if (count > mid){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
        
    }
};
