class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1;i<=num2;i++){
            string digits = to_string(i);
            if(digits.size()<3) continue;
            for(int j = 1;j<digits.size()-1;j++){
                if((digits[j] < digits[j+1] && digits[j] < digits[j-1]) || (digits[j] > digits[j+1] && digits[j] > digits[j-1])) ans++;
            }
        }
        return ans;
    }
};