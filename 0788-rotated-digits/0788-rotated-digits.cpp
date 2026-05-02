class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for(int i =0;i<=n;i++){
            bool possible = false;
            int temp = i;
            bool valid = true;
            while(temp > 0){
                int digit = temp % 10;
                if(digit == 3 || digit == 4 || digit == 7){
                    valid = false;
                    break;
                }
                if(digit == 2 || digit == 5 || digit == 6 || digit == 9){
                    possible = true;
                }
                temp /= 10;
            }
            if(valid && possible) count++;
        }
        return count;
    }
};