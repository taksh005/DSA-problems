class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int maxLength = n * m;
        vector<vector<int>> shiftedGrid(n,vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m;j++){
                int length = (m * i + j + k)  % maxLength;
                int row , col;
                row = (length / m);
                col = length % m;
                shiftedGrid[row][col] = grid[i][j];
            }
        }
        return shiftedGrid;
    }
};