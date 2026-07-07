class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        string nums = to_string(n);
        int newN = 0;
        for(int i = 0; i < nums.length(); i++){
            if(nums[i] - '0' != 0){
                newN = newN * 10 + (nums[i] - '0');
                sum += (nums[i] - '0');
            }else continue;
        }
        long long ans = 1LL*newN * sum;
        return ans;
    }
};