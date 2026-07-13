class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int,int> rank;
        int current_rank = 1;
        for(int i = 0; i < n; i++){
            if (rank.find(sortedArr[i]) == rank.end()) {
                rank[sortedArr[i]] = current_rank;
                current_rank++;
            }
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = rank[arr[i]];
        }
        return ans;
    }
};