class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_prod = nums[0];
        int prefix = 1;
        int suffix = 1;
        for(int i =0;i<n;i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            max_prod = max({prefix,suffix,max_prod});
        }
        return max_prod;
    }
};