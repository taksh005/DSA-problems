class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans(n,0);
        for(auto it : matrix){
            for(int i = 0;i<n;i++){
                ans[i] += it[i];
            }
        }
        return ans;
    }
};