class Solution {
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(string &str) {
        // Write your code here
        unordered_map <char, int> mp;
        for (auto ch:str){
            mp[ch]++;
        }
        for (auto ch:str){
            if (mp[ch]==1)
            {
                return ch;
            }
        }
        return 'a';

    }
};
