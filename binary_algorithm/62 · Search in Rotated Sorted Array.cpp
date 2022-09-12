class Solution {
public:
    /**
     * @param a: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     就是分两种情况，其他情况都不单调另算。
     */
    int search(vector<int> &nums, int target) {
        // write your code here
        if (nums.empty()) return -1;
        int left = 0;
        int right = nums.size()-1;
        while (left < right){
            int mid = (left+right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[left] > nums[mid]){
                if (nums[right] >= target && target >= nums[mid]){
                    left = mid+1;
                }
                else{
                    right = mid;
                }
            }
            else {
                if (nums[left] <= target && target <= nums[mid]){
                    right = mid;
                }
                else{
                    left = mid+1;
                }
            }
        }
        
        if (nums[left]==target) return left;
        return -1;
    }
};
