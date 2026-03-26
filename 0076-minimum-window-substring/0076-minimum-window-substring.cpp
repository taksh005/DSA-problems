class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        int minW = INT_MAX;
        vector<int> hash(128,0);
        for(char c : t) hash[c]++;
        int left = 0;
        int right = 0;
        int head = 0;
        while(right<n){
            if(hash[s[right++]]-- > 0) m--;
            while(m == 0){
                if(right - left < minW) minW = right - (head = left);
                if(hash[s[left++]]++ == 0) m++;
            }
        }
        return minW == INT_MAX ? "":s.substr(head,minW);
    }
};