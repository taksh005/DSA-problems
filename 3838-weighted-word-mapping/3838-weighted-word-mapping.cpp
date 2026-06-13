class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string res = "";
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(char c : words[i]){
                sum += weights[c - 'a'];
            }
            int after_mod = sum % 26;
            res += ('z' - after_mod);
        }
        return res;
    }
};