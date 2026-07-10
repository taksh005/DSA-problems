class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> sorted_nums;
        for(int i = 0; i < n; i++){
            sorted_nums.push_back({nums[i], i});
        }
        sort(sorted_nums.begin(), sorted_nums.end());
        vector<int> orig_to_sorted(n);
        for (int i = 0; i < n; i++) {
            orig_to_sorted[sorted_nums[i].second] = i;
        }
        vector<int> comp(n, 0);
        int curr_comp = 0;
        for(int i = 1; i <n ;i++){
            if(abs(sorted_nums[i].first - sorted_nums[i-1].first) > maxDiff){
                curr_comp++;
            }
            comp[i] = curr_comp;
        }
        int MAX_BITS = 20; 
        vector<vector<int>> up(n, vector<int>(MAX_BITS));
        int r = 0;
        for (int l = 0; l < n; l++) {
            while (r + 1 < n && 1LL * sorted_nums[r + 1].first - sorted_nums[l].first <= maxDiff) {
                r++;
            }
            up[l][0] = r;
        }
        for (int k = 1; k < MAX_BITS; k++) {
            for (int i = 0; i < n; i++) {
                up[i][k] = up[up[i][k - 1]][k - 1];
            }
        }
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int pos_u = orig_to_sorted[q[0]];
            int pos_v = orig_to_sorted[q[1]];
            if (pos_u == pos_v) {
                ans.push_back(0);
                continue;
            }
            if (comp[pos_u] != comp[pos_v]) {
                ans.push_back(-1);
                continue;
            }
            if (pos_u > pos_v) {
                swap(pos_u, pos_v);
            }
            int curr = pos_u;
            int steps = 0;
            for (int k = MAX_BITS - 1; k >= 0; k--) {
                if (up[curr][k] < pos_v) {
                    curr = up[curr][k];
                    steps += (1 << k);
                }
            }
            ans.push_back(steps + 1);
        }
        
        return ans;
    }
};