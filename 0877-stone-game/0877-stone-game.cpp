class Solution {
private:
    int solution(int i, int j, vector<vector<int>>& dp, vector<int>& piles){
        if(i == j) return dp[i][j] = piles[i];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(piles[i] - solution(i+1,j,dp,piles), piles[i] - solution(i,j-1,dp,piles));
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solution(0,n-1,dp,piles) >= 0;
    }
};