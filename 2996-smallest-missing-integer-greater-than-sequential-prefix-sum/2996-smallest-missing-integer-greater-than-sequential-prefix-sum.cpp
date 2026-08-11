class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        unordered_set<int> num_set(nums.begin(), nums.end());
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i-1] == 1){
                sum += nums[i];
            }else break;
        }
        while(num_set.count(sum)) sum += 1;
        return sum;
    }
};