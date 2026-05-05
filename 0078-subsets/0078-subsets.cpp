class Solution {
public:
    void ss(vector<int>& a,int idx, int n, vector<int>& temp, vector<vector<int>>& ans){
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        ss(a,idx+1,n,temp,ans);
        temp.push_back(a[idx]);
        ss(a,idx+1,n,temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        ss(nums,0,n,temp,ans);
        return ans;
    }
};