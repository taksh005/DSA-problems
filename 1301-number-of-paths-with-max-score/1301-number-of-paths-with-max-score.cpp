class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        vector<vector<int>> paths(n + 1,vector<int>(n+1,0));
        vector<vector<int>> max_score(n + 1,vector<int>(n+1,-1));
        max_score[n - 1][n - 1] = 0;
        paths[n - 1][n - 1] = 1;
        for(int i =n-1 ;i >= 0;i--){
            for(int j = n-1;j>=0;j--){
                if ((i == n - 1 && j == n - 1) || board[i][j] == 'X') {
                    continue;
                }
                int m_score = max({max_score[i + 1][j], max_score[i][j + 1], max_score[i + 1][j + 1]});
                if (m_score == -1) {
                    continue;
                }
                int val = (board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                max_score[i][j] = m_score + val;
                long long total_paths = 0;
                if (max_score[i + 1][j] == m_score) {
                    total_paths = (total_paths + paths[i + 1][j]) % MOD;
                }
                if (max_score[i][j + 1] == m_score) {
                    total_paths = (total_paths + paths[i][j + 1]) % MOD;
                }
                if (max_score[i + 1][j + 1] == m_score) {
                    total_paths = (total_paths + paths[i + 1][j + 1]) % MOD;
                }
                
                paths[i][j] = total_paths;
            }
        }
        if (max_score[0][0] == -1) {
            return {0, 0};
        }
        
        return {max_score[0][0], paths[0][0]};
    }
};