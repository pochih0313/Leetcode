class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up
        
        int col = 0;
        int row = 0;
        int num = 1;
        int d = 0;
        while(num <= n * n) {
            result[row][col] = num++;
            int nRow = row + dir[d][0];
            int nCol = col + dir[d][1];
            
            if ((nRow >= n) || (nRow < 0) || (nCol >= n) || (nCol < 0) || (result[nRow][nCol] != 0)) {
                if (d == 3)
                    d = 0;
                else 
                    d++;
            }
            
            row += dir[d][0];
            col += dir[d][1];
        }
        
        return result;
    }
};