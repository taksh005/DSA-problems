class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(3,0);
        for(int i = n - 1; i >= 0; i--){
            int max_diff = INT_MIN;
            int curr_sum = 0;
            for(int x =1; x <= 3 && i + x - 1 < n; x++){
                curr_sum += stoneValue[i + x - 1];
                max_diff = max(max_diff, curr_sum - dp[(i + x) % 3]);
            }
            dp[i % 3] = max_diff;
        }
        if(dp[0] > 0){
            return "Alice";
        }
        else if(dp[0] < 0) return "Bob";
        else return "Tie";
    }
};