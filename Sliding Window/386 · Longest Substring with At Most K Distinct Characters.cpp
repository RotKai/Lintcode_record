class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        if (s.empty() || k==0) return 0;
        unordered_map<char,int> mp;
        int max_size = 1;
        for (int i=0, j=0; i < s.size(); ++i){
            mp[s[i]]++;
            while (mp.size() > k && j < i){
                mp[s[j]]--;
                if (mp[s[j]] == 0) 
                    mp.erase(s[j]);
                j ++;
            }
            max_size = max(max_size,i-j+1);
        }
        return max_size;
    }
};
