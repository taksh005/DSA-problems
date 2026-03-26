class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash(26,0);
        if(t.size()!=s.size()) return false;
        for(char c : s) hash[c-'a']++;
        for(int i =0;i<s.size();i++){
            if(hash[t[i]]-- <= 0) return false;
        }
        return true;
    }
};