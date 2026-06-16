class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(char c : s){
            int n = res.size() == 0 ? 0 : res.size() - 1;
            if(res == "" && (c == '*' || c == '#' || c == '%')) continue;
            else if(c == '#') res += res; 
            else if(c == '*') res.erase(n,1);
            else if(c == '%') reverse(res.begin(),res.end());
            else res += c;
        }
        return res;
    }
};