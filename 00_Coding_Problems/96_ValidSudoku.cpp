class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<int, 10> nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j]-'0' >= 1 && board[i][j]-'0'<= 9) {
                    if(nums[board[i][j]-'0'] != 0)
                        return false;
                    else
                        nums[board[i][j]-'0'] = 1;
                }
            }
            for(int r = 1; r < 10; r++)
                nums[r] = 0;
        }
        for(int j = 0; j < 9; j++) {
            for(int i = 0; i < 9; i++) {
                if(board[i][j]-'0' >= 1 && board[i][j]-'0' <= 9) {
                    if(nums[board[i][j]-'0'] != 0)
                        return false;
                    else
                        nums[board[i][j]-'0'] = 1;
                }
            }
            for(int r = 1; r < 10; r++)
                nums[r] = 0;
        }
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = i*3; k < i*3 + 3; k++) {
                    for(int l = j*3; l < j*3 + 3; l++) {
                        if(board[k][l]-'0' >= 1 && board[k][l]-'0' <= 9) {
                            if(nums[board[k][l]-'0'] != 0)
                                return false;
                            else
                                nums[board[k][l]-'0'] = 1;
                        }
                    }
                }
                for(int r = 1; r < 10; r++)
                    nums[r] = 0;
            }
        }
        return true;
    }
};