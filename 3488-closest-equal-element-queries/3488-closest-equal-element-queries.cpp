class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> ans(queries.size());
        vector<int> closest_dist(n, -1);
        unordered_map<int,vector<int>> mpp;
        for(int i =0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto& [value,pos] : mpp){
            int k = pos.size();
            if(k<=1) continue;
            for(int i = 0; i < k; i++){
                int curr = pos[i];
                int left_match = pos[(i-1+k)%k];
                int right_match = pos[(i+1)%k]; 
                int left_dist = (curr - left_match + n) % n;
                int right_dist = (right_match - curr + n) % n;
                closest_dist[curr] = min(left_dist, right_dist);
            }
        }
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = closest_dist[queries[i]];
        }
        return ans;
    }
};