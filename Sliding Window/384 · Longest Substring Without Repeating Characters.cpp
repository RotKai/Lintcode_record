class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s) {
        // write your code here
        if (s.empty()) return 0;
        unordered_map<char,int> mp;
        int max_len = 1;
        for (int i=0, j=0; i < s.size(); ++i){
            mp[s[i]] ++; 
            while (mp[s[i]] > 1 && j < i){
                mp[s[j++]]--;
            }
            max_len = max(max_len,i-j+1);
        }
        return max_len;
    }
};
