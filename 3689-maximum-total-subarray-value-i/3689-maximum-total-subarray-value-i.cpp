class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int max_nums = *max_element(nums.begin(),nums.end());
        int min_nums = *min_element(nums.begin(),nums.end());
        return 1ll*k*(max_nums-min_nums);
    }
};