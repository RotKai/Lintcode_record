class Solution {
public:
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &s, string &target) {
        // write your code here
        if(s.size() < target.size()) return "";
        int n = s.size();
        unordered_map<int,int> s_mp,t_mp;
        for (auto ch:target) t_mp[ch]++;
        int match = 0;
        string ans;
        for (int right=0,left=0;right <n; right++){
            s_mp[s[right]] ++;
            if (s_mp[s[right]] <= t_mp[s[right]])  match ++;
            while (s_mp[s[left]] > t_mp[s[left]]){
                s_mp[s[left++]]--;
            }
            if (match == target.size()){
                if (ans.empty() || right-left+1 < ans.length()){
                    ans = s.substr(left,right-left+1); 
                }
            }
        }
        return ans;
    }
};
