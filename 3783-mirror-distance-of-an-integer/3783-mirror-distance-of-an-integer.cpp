class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        string res = "";
        for(int i= s.size() - 1;i>=0;i--){
            res += s[i];
        }
        int r = stoi(res);
        return abs(r - n);
    }
};