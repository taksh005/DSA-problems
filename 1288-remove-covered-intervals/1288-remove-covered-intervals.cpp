class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b){
        if (a[0] == b[0]) return a[1] > b[1]; 
        return a[0] < b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        sort(intervals.begin(), intervals.end(), compare);
        int max_r = intervals[0][1];
        for(int i =1; i < n; i++){
            if(max_r >= intervals[i][1]){
                count++;
            }else max_r = max(max_r,intervals[i][1]);
        }
        return n - count;
    }
};