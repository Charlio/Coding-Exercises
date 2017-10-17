class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                bool wordFound = exist(board, word, i, j, 0);
                if(wordFound) return true;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word, int i, int j, int pos) {
        if(word.length() == pos) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[pos]) return false;
        board[i][j] ^= 0xFF;
        bool wordFound = exist(board, word, i-1, j, pos+1) || exist(board, word, i+1, j, pos+1) || exist(board, word, i, j-1, pos+1) || exist(board, word, i, j+1, pos+1);
        board[i][j] ^= 0xFF;
        return wordFound;
    }
    
};