class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        vector<int> res(n);
        for(int x : nums) total_sum += x;
        int left_sum = 0;
        for(int i = 0;i<n;i++){
            i > 0 ? left_sum += nums[i-1] : left_sum = 0;
            res[i] = abs(total_sum - nums[i] - 2*left_sum);
        }
        return res;
    }
};