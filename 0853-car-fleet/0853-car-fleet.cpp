class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        map<int,double> mpp;
        for(int i =0 ;i<n;i++){
            mpp[-position[i]] = (double)(target - position[i])/speed[i];
        }
        int ans = 0;
        double cur = 0;
        for(auto it : mpp){
            if(it.second > cur){
                cur = it.second;
                ans++;
            }
        }
        return ans;

    }
};