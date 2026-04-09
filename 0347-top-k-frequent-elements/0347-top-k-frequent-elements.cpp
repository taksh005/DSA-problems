class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> count;
        for(int i = 0;i<n;i++){
            count[nums[i]]++;
        }
        vector<vector<int>> x(n+1);
        for(auto &[num,freq] : count){
            x[freq].push_back(num);
        }
        for(int i = n;i>=1;i--){
            for(auto num : x[i]){
                ans.push_back(num);
                if(ans.size() >= k) return ans;
            }
        }
        return ans;
    }
};