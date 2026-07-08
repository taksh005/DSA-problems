class Solution {
public:
    long long MOD = 1e9 +7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> count(n+1, 0);
        vector<long long> sum(n+1, 0);
        vector<long long> val(n + 1, 0);
        vector<long long> power10(n+1,1);
        for (int i = 1; i <= n; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }
        for(int i = 0; i < n; i++){
            int digit = s[i] - '0';
            count[i+1] = count[i];
            sum[i+1] = sum[i] + digit;
            val[i+1] = val[i];
            if(digit){
                count[i+1]++;
                val[i+1] = (val[i] * 10 + digit) % MOD;
            }
        }
        int q = queries.size();
        vector<int> ans(q);
        for(int i = 0; i < q; i++){
            int l = queries[i][0] + 1;
            int r = queries[i][1] + 1;
            long long curr_sum = sum[r] - sum[l-1];
            int k = count[r] - count[l - 1];
            long long prefix_to_remove = (val[l - 1] * power10[k]) % MOD;
            long long newN = (val[r] - prefix_to_remove + MOD) % MOD;
            ans[i] = (newN * curr_sum) % MOD;
        }
        return ans;
    }
};