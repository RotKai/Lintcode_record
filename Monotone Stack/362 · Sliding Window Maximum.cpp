/*
动态维护窗口使得deque中单调递减（下标中的元素）
*/


class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @param k: An integer
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        if (nums.empty()) return {};
        deque<int> q;
        vector<int> ans;
        for (int i=0; i<k; ++i){
            while (!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        for (int i=k; i<nums.size(); ++i){
            while (!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            if (q.front() <= i-k){
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
