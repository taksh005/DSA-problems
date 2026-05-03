class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        if(n != goal.length()) return false;
        string s2 = s + s;
        return s2.find(goal) != string::npos;
    }
};