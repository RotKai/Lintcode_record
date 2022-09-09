class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    

    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &vis, string &word, int row, int col, int index){
        if (row >= board.size() || row<0 || col <0 || col >= board[0].size() || board[row][col] != word[index] || vis[row][col]) 
        {
            return false;
        }
        if (index == word.size()-1) return true;

        vis[row][col] = true;
        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        bool flag = false;
        for (auto dir:dirs){
            bool is_find = dfs(board, vis, word, row + dir.first, col + dir.second, index+1);
            if (is_find){
                flag = true;
                break;
            }
        }
        vis[row][col] = false;
        return flag;
    }


    bool exist(vector<vector<char>> &board, string &word) {
        // write your code here
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        for (int i=0; i<m; ++i)
            for (int j=0; j<n;++j){
                bool flag =  dfs(board, vis, word, i, j , 0);
                if (flag) return true;
            }
    return false;
    }
};
