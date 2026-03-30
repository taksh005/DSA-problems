class Solution {
public:
    bool check(vector<int> &nums, int len){
        int n = nums.size();
        int mini = 0;
        for(int i = 0;i<n;i+=len){
            if(nums[i] < mini) return false;
            int maxi = nums[i];
            bool point = false;
            for(int j = i+1;j<i+len; j++){
                if(nums[j] < mini) return false;
                if (nums[j - 1] > nums[j]) {
                    if (point) return false;
                    point = true;
                }
                maxi = max(maxi, nums[j]);
            }
            if(point){
                if(nums[i]<nums[i+len-1]) return false;
            }
        mini = maxi;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            if (check(nums, k)) ans += k;
        }
        
        return ans;
    }
};