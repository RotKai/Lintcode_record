class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // Write your code here
        if (s.size()<k) return s.size();
        unordered_map<char,int> mp;
        int ans = k;
        int i = 0;
        for (int j=0; j<s.size(); j++){
            mp[s[j]]++;
            while (mp.size()>k){
                mp[s[i]]--;
                if (mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};
