/*
跟1737题一样
*/

class Solution {
public:
    /**
     * @param s: a string
     * @return: the length of the longest substring T that contains at most 2 distinct characters
     */
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        // Write your code here
        if (s.size()<3) return s.size();
        unordered_map<char,int> mp;
        int ans = 2;
        int i = 0;
        for (int j=0; j<s.size(); j++){
            mp[s[j]]++;
            while (mp.size()>2){
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
