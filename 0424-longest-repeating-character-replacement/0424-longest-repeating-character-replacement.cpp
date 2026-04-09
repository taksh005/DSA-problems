class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0); 
        int left = 0;
        int max_freq = 0;
        int max_window = 0;
        for(int right = 0;right<s.length();right++){
            counts[s[right] - 'A']++;
            max_freq = max(max_freq,counts[s[right] - 'A']);
            int length = right - left + 1;
            if(length - max_freq > k){
                counts[s[left] - 'A']--;
                left++;
            }
            max_window = max(max_window,right - left +1);
        }
        return max_window;
    }
};