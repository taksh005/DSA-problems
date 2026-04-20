class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxD = 0;
        for(int i = 0;i<(n/2 + 1);i++){
            for(int j = i;j<n;j++){
                if(colors[i] != colors[j]){
                    maxD = max(maxD, abs(i-j));
                }
            }
        }
        return maxD;
    }
};