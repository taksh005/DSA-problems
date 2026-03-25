class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> digits;
        for(auto it : nums){
            digits.push_back(to_string(it));
        }
        sort(digits.begin(),digits.end(),[](string a, string b){
            return a+b > b+a;
        });
        if(digits[0] == "0") return "0";
        string ans = "";
        for(auto &s : digits) ans += s;
        return ans;
    }
};