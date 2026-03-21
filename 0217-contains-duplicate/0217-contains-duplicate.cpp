class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i =1;i<n-1;i+2){
            if(nums[i] == nums[i-1] || nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};