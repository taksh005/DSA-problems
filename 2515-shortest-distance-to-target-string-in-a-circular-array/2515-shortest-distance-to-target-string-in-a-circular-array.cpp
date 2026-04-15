class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int min_dist = n;
        for(int i = 0;i<n;i++){
            if(words[i] == target){
                int shortest_path = min(abs(i - startIndex), n - abs(i - startIndex));
                min_dist = min(min_dist, shortest_path); 
            }
        }
        return min_dist == n ? -1 : min_dist;
    }
};