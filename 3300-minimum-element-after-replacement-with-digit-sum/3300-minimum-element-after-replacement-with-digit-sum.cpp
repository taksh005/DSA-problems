class Solution {
private:
    int digits_sum(int x, int sum){
        if(x == 0) return sum;
        int digit = x%10;
        sum += digit;
        return digits_sum(x/10, sum);
    }
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> num_sum(n);
        for(int i = 0;i<n;i++){
            num_sum[i] = digits_sum(nums[i], 0);
        }
        return *min_element(num_sum.begin(),num_sum.end());
    }
};