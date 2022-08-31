/*
不得不说这题目真的好绕啊，没怎么看懂，一开始强行遍历超时了，用滑动窗口大幅减少运行时间
*/

class Solution {
public:
    /**
     * @param tree: The type of fruit
     * @return: The total amount of fruit you can collect.
     */
    int totalFruit(vector<int> &tree) {
        // write your code here
        int n = tree.size();
        if (n<3) return n;
        int max_len = 2;
        unordered_map<int,int> mp;
        int i = 0;
        for (int j=0; j<n;j++){
            mp[tree[j]]++;
            while (mp.size()>2){
                mp[tree[i]]--;
                if (mp[tree[i]]==0)
                    mp.erase(tree[i]);
                ++i;
            }
            max_len = max(max_len,j-i+1);
        }
        return max_len;
    }
};
