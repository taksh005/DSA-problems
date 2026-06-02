class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int minL = INT_MAX, minW = INT_MAX;
        int ans = INT_MAX;
        for(int i = 0 ;i<n;i++){
            minL = min(minL, landStartTime[i] + landDuration[i]);
        }
        for(int i = 0 ;i<m;i++){
            minW = min(minW, waterStartTime[i] + waterDuration[i]);
            ans = min(ans, max(minL,waterStartTime[i]) + waterDuration[i]);
        }
        for(int i = 0 ;i<n;i++){
            ans = min(ans, max(minW,landStartTime[i]) + landDuration[i]);
        }
        return ans;
    }
};