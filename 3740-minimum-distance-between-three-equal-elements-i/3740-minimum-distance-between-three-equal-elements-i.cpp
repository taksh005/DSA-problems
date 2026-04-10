class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int minDistance = INT_MAX;
        vector<vector<int>> count(n+1);
        for(int i = 0; i < n; i++){
            count[nums[i]].push_back(i);
        }
        for(auto it : count){
            int distance = 0;
            if(it.size() == 3){
                distance = abs(it[0] - it[1]) + abs(it[1] - it[2]) + abs(it[2] - it[0]);
                minDistance = min(distance, minDistance);
            }else if(it.size() > 3){
                for(int j = 0;j<=it.size() - 3;j++){
                    distance = abs(it[j] - it[j+1]) + abs(it[j+1] - it[j+2]) + abs(it[j+2] - it[j]);
                    minDistance = min(distance,minDistance);
                }
            }
        }
        return (minDistance != INT_MAX) ? minDistance : -1;
    }
};