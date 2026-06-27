class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,int> hash;
        for(int i = 0; i < n; i++){
            hash[nums[i]]++;
        }
        int ans = 1;
        if(hash.count(1)){
            ans = max(ans,hash[1] %2 ? hash[1] : hash[1] - 1);
        }
        for(auto &[nums,f] : hash){
            if(nums == 1) continue;
            long long x = nums;
            int len = 0;
            while(hash.count(x) && hash[x] >= 2){
                len+=2;
                if(x>1e9) break;
                x = x*x;
            }
            if(hash.count(x)) len++;
            else len--;
            ans = max(ans,len);
        }
        return ans;
    }
};