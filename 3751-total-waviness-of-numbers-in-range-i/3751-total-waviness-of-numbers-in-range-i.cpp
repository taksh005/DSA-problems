class Solution {
private:
    void digits_vector(int x,vector<int>& digits){
        if(x == 0) return;
        digits.push_back(x%10);
        return digits_vector(x/10,digits);
    }
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int j = num1; j <= num2; j++){
            vector<int> digits;
            digits_vector(j,digits);
            if(digits.size() < 3) {
                continue;
            }
            for(int i = 1; i< digits.size() - 1;i++){
                if((digits[i] > digits[i+1] && digits[i] > digits[i-1]) || (digits[i] < digits[i+1] && digits[i] < digits[i-1])){
                    ans++;
                }
            } 
        }
        return ans;
    }
};