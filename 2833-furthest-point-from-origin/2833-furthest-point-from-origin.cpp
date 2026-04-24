class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0;
        int r = 0;
        int nil = 0;
        for(char c:moves){
            if(c == 'L') l++;
            else if(c == 'R') r++;
            else nil++;
        }
        return abs(l - r) + nil;    
    }
};