class Solution {
private:
    int solution(int i, int j, vector<vector<int>>& dp, vector<int>& nums){
        if(dp[i][j] != -1) return dp[i][j];
        if(i == j) return dp[i][j] = nums[i];
        return dp[i][j] = max(nums[i] - solution(i + 1, j, dp, nums), nums[j] - solution(i, j -1, dp, nums));
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solution(0, n-1, dp, nums) >= 0;
    }
};