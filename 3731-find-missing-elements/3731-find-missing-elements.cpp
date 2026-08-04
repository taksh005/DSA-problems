class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int maxn = INT_MIN;
        int minn = INT_MAX;
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxn) maxn = nums[i];
            if(nums[i] < minn) minn = nums[i];
            s.insert(nums[i]);
        }
        vector<int> ans;
        for(int i = minn; i < maxn; i++){
            if(s.find(i) == s.end()) ans.push_back(i);
        }
        return ans;
    }
};