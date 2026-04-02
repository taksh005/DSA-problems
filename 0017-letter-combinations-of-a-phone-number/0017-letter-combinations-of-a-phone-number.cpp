class Solution {
public:
    vector<string> mapping = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void solve(int id, int charId, string& temp, string& digits){
        if(id == digits.size()){
            ans.push_back(temp);
            return;
        }
        string& chars = mapping[digits[id] - '0' - 2];
        if(charId == chars.size()) return;
        temp+= chars[charId];
        solve(id+1,0,temp,digits);
        temp.pop_back();
        solve(id,charId+1,temp,digits);
    }
    vector<string> letterCombinations(string digits) {
        string temp = "";
        solve(0,0,temp,digits);
        return ans;
    }
};