/*
一开始想到了哈希表，但是不知道怎么把单词放进数组里，看了官方解答才发现可以统一把string放到哈希表的key里，后面的就没有难点了
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &words) {
        // write your code here
        unordered_map<string,vector<string>> mp;
        for (const string &word:words){
            string new_word = word;
            sort(new_word.begin(),new_word.end());
            mp[new_word].emplace_back(word);
        }
        vector<vector<string>> ans;
        for (auto &[word,vec]:mp){
            ans.push_back(vec);
        };
        return ans;
    }
};
