class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int> freq(26,0);
        int diff =0 ;
        for(char c : word){
            freq[c - 'a']++;
            if(freq[c - 'a'] == 1) diff++;
        }
        sort(freq.rbegin(), freq.rend());
        int ans = 0;
        for(int i = 1;i <= 26; i++){
            if(freq[i-1] == 0) return ans;
            else if(i <= 8) ans += freq[i-1];
            else if(i > 8 && i <= 16) ans += 2*freq[i-1];
            else if(i > 16 && i <= 24) ans += 3*freq[i-1];
            else ans += 4 * freq[i-1];
        }
        return ans;
    }
};