class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = m*n-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            int mid_val = matrix[mid/m][mid%m];
            if(mid_val == target) return true;
            if(mid_val > target) high = high - 1;
            if(mid_val < target) low = 1 + low;
        }
        return false;
    }
};