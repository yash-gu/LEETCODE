class Solution {
    bool check(int i, int j, vector<vector<char>>& board) {
        int startRow = (i / 3) * 3;
        int startCol = (j / 3) * 3;

        for (int k = 0; k <= 2; k++) {
            int ni = startRow + k;
            for (int l = 0; l <= 2; l++) {
                int nj = startCol + l;
                
                if (ni == i && nj == j) continue;
                
                if (board[ni][nj] == board[i][j]) return false;
            }
        }

        for (int c = 0; c < 9; c++) {
            if (c != j && board[i][c] == board[i][j]) return false;
        }

        for (int r = 0; r < 9; r++) {
            if (r != i && board[r][j] == board[i][j]) return false;
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { 
                if (board[i][j] != '.') {
                    if (!check(i, j, board)) return false;
                }
            }
        }
        return true;
    }
};
