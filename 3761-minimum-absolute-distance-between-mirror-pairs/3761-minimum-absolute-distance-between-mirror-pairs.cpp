class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> hash;
        int ans = 100000, i = 0;
        for(int & n: nums){
            int r;
            if(hash.count(n)) ans = min(ans, i - hash[n]);
            for(r =0;n;n/=10) r = r*10 + (n%10);
            hash[r] = i++; 
        }
        return -(ans == 100000) | ans;
    }
};