class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int less_pivot = 0;
        int more_pivot = n-1;
        vector<int> res(n);
        int j = n-1;
        for(int i = 0;i<n;i++){
            if(nums[i] < pivot) res[less_pivot++] = nums[i];
            if(nums[j] > pivot) res[more_pivot--] = nums[j];
            j--;
        }
        while (less_pivot <= more_pivot) {
            res[less_pivot++] = pivot;
        }
        return res;
    }
};