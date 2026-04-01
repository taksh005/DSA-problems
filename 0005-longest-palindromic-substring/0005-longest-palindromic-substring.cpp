class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        string ans = "";
        for(int i = 0;i<n;i++){
            int l = i;
            int r = i;
            while(l>=0 && r<n && s[l] == s[r]){
                l--;
                r++;
            }
            string temp = s.substr(l+1,r-l-1);
            if(temp.size()>ans.size()) ans = temp;

            l = i;
            r= i+1;
            while(l>=0 && r<n && s[l] == s[r]){
                l--;
                r++;
            }
            temp = s.substr(l+1,r-l-1);
            if(temp.size()>ans.size()) ans = temp;
        }
        return ans;
    }
};