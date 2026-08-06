class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int j = n; ; j++){
            int product = 1;
            int i = j;
            while(i != 0){
                int digit = i % 10;
                product *= digit;
                i /= 10;
            }
            if(product % t == 0) return j;
        }
        return -1;
    }
};