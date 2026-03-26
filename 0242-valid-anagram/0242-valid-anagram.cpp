class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash(128,0);
        if(t.size()>s.size()) return false;
        for(char c : s) hash[c]++;
        int i = 0;
        while(i<s.size()){
            if(hash[t[i++]]-- <= 0) return false;
        }
        return true;
    }
};