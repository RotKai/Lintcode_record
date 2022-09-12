class Solution {
public:
    /**
     * @param nums: the array of integers
     * @param target: 
     * @return: the starting and ending position
     */
    int mysearch (vector<int> &nums, float target){
        int left = 0;
        int right = nums.size()-1;
        while (left < right){
            int mid = (left+right) / 2;
            if (nums[mid] > target){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
    vector<int> searchRange(vector<int> &nums, int target) {
        // Write your code here.

        
        // 初始化（size只有1）
        if (nums.size()==1 && target == nums[0]){
            return {0,0};
        }
        if (nums.size()==1 && target != nums[0]){
            return {-1,-1};
        }

        int start = mysearch(nums,target-0.5);
        int end = mysearch(nums,target+0.5)-1;
        start = nums[start]==target ? start:-1;
        end = nums[end]==target ? end:-1;
        return {start,end};
    }
};
