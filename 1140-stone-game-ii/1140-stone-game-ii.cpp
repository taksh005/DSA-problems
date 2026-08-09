class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> suffixSum(n + 1, 0);
        for(int i = n - 1; i >= 0; i--){
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        for(int i = 0; i <= n; i++){
            dp[i][n] = suffixSum[i];
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j >= 1; j--){
                for(int x = 1; x <= 2*j && i + x <= n; x++){
                    dp[i][j] = max(dp[i][j], suffixSum[i] - dp[i+x][max(j,x)]);
                }
            }
        }
        return dp[0][1];
    }
};