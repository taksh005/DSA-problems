class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int> count(26, 0);
        int start = 0;
        int maxLength = 0;
        for(int i = 0; i < n; i++){
            count[s[i] - 'a']++;
            while(count[s[i] - 'a'] > 2){
                count[s[start]-'a']--;
                start++;
            }
            maxLength = max(maxLength, i - start + 1);
        }
        return maxLength;
    }
};