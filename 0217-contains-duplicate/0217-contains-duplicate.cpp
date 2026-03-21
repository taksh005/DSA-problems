class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> count;
        for(int i =0;i<n;i++){
            count[nums[i]] += 1;
            if(count[nums[i]] > 1) return true;
        }
        return false;
    }
};