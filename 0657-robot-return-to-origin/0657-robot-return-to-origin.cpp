class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int> mapping = {{'R',0},{'L',0},{'U',0},{'D',0}};
        for(char c : moves) mapping[c]++;
        if(mapping['R']!=mapping['L'] || mapping['U']!= mapping['D']) return false;
        return true;
    }
};