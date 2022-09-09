class Solution {
public:
    /**
     * @param nums: the given array
     * @return: if any value appears at least twice in the array
     */
    bool containsDuplicate(vector<int> &nums) {
        // Write your code here
        unordered_set<int> st;
        for (auto num:nums){
            if (st.count(num)){
                return true;
            }
            else{
                st.insert(num);
            }
        } 
    return false;
    }
};
