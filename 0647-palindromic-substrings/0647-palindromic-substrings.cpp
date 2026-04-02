class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        string a = "";
        for(int i = 0;i<n;i++){
            int l = i;
            int r= i;
            while(l>=0 && r< n && s[l] == s[r]){
                l--;
                r++;
                count++;
            }
            l = i;
            r = i+1;
            while(l>=0 && r< n && s[l] == s[r]){
                l--;
                r++;
                count++;
            }
        }
        return count;
    }
};