class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        unordered_map<int, int> hash;
        for(auto seat : reservedSeats){
            if(seat[1] >= 2 && seat[1] <= 9){
                hash[seat[0]] |= (1 << (seat[1] - 2));
            }
        }
        int ans = (n - hash.size()) * 2;
        for(auto& [row, bitmask] : hash){
            if(((bitmask | 0b11110000) == 0b11110000) || ((bitmask | 0b11000011) == 0b11000011) || ((bitmask | 0b00001111) == 0b00001111)) ans++;
        }
        return ans;
    }
};