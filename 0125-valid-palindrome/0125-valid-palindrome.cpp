class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0 ;
        int r = n-1;
        while(l < r){
            if(isalnum(s[l]) && isalnum(s[r]) && tolower(s[l]) == tolower(s[r])){
                l++;
                r--;
            }
            else if(!isalnum(s[l])){
                l++;
            }
            else if(!isalnum(s[r])){
                r--;
            }else{
                return false;
            }
        }
        return true;
    }
};