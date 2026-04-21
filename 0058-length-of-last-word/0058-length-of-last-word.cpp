class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n-1;
        int count = 0;
        for(i;i>=0;i--){
            if(s[i] != ' '){
                count++;
            }
            else if(s[i] == ' ' && count !=0) break;
        }
        return count;
    }
};