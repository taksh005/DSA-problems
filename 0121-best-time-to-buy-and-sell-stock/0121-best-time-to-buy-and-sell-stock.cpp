class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int bought = prices[0];
        int profit = 0;
        for(int i =0;i<n;i++){
            if(bought > prices[i]){
                bought = prices[i];
            }
            profit = max(profit, prices[i] - bought);
        }
        return profit;
    }
};