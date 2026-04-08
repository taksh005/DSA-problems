class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i = 0;i<queries.size();i++){
            int idx = queries[i][0];
            while(idx<=queries[i][1]){
                nums[idx] = 1ll*nums[idx] * queries[i][3]%int(1e9 + 7);
                idx += queries[i][2];
            }
        }
        int ans = nums[0];
        for(int i =1;i<nums.size();i++){
            ans = ans^nums[i];
        }
        return ans;
    }
};