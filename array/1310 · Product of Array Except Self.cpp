
class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the product of all the elements of nums except nums[i].
     */
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n,1);
        int premul = 1;
        int postmul = 1;
        for (int i=0; i<n; ++i ){
            res[i] *= premul;
            
            premul *= nums[i];
        }

        for (int i=n-1; i>=0; --i ){
            res[i] *= postmul;
            postmul *= nums[i];
        }
        return res;

    }
};
