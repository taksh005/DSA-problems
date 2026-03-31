class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> map = {{')','('},{'}','{'},{']','['}};
        stack<char> stack;
        for(char c: s){
            if(map.find(c) == map.end()) stack.push(c);
            else if(!stack.empty() && map[c] == stack.top()) stack.pop();
            else return false;
        }
        return stack.empty();
    }
};