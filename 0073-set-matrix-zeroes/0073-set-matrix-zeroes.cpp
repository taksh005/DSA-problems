class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool zero_in_first_row = false;
        bool zero_in_first_col = false;
        for(int i =0;i<rows;i++){
            if(matrix[i][0] == 0){
                zero_in_first_col = true;
                break;
            }
        }
        for(int j = 0;j<cols;j++){
            if(matrix[0][j] == 0){
                zero_in_first_row = true;
                break;
            }
        }
        for(int i =1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < rows; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < cols; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < cols; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < rows; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(zero_in_first_row) {
            for(int j = 0; j < cols; j++) {
                matrix[0][j] = 0;
            }
        }
        if(zero_in_first_col) {
            for(int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        } 
    }
};