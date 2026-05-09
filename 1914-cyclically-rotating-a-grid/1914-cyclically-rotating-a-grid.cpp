class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m,n)/2;
        for(int layer =0; layer<layers;layer++){
            vector<int> val;
            int top = layer;
            int left = layer;
            int bottom = m - 1 - layer;
            int right = n - 1 - layer;
            for(int i = left; i <= right;i++) val.push_back(grid[top][i]);
            for(int j = top + 1; j <= bottom -1; j++) val.push_back(grid[j][right]);
            for(int i = right; i >= left; i--) val.push_back(grid[bottom][i]);
            for(int j = bottom - 1; j >= top+1; j--) val.push_back(grid[j][left]);
            int s = val.size();
            int start = k % s;
            int idx = start;
            for(int j = left;j<=right;j++){
                grid[top][j] = val[idx];
                idx++;
                if(idx == s) idx =0;
            }
            for(int i = top + 1; i <= bottom -1 ;i++){
                grid[i][right] = val[idx];
                idx++;
                if(idx == s) idx =0;
            }
            for(int j = right;j>=left;j--){
                grid[bottom][j] = val[idx];
                idx++;
                if(idx == s) idx =0;
            }
            for(int i = bottom - 1;i >= top + 1;i--){
                grid[i][left] = val[idx];
                idx++;
                if(idx == s) idx = 0;
            }
        }
        return grid;
    }
};