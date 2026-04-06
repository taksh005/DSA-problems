class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        set<pair<int,int>> obstacle;
        for(auto o:obstacles){
            obstacle.insert({o[0],o[1]});
        }
        int x= 0,y = 0;
        int dir = 0;
        int maxdist = 0;
        for(int i : commands){
            if(i == -1) dir = (dir+1)%4;
            else if(i == -2) dir = (dir+3)%4;
            else{
                while(i--){
                    int dx = x + directions[dir].first;
                    int dy = y+ directions[dir].second;
                    if(obstacle.count({dx,dy})) break;
                    x = dx;
                    y = dy;
                    maxdist =max(maxdist,x*x + y*y);
                }
            }
        }
        return maxdist;
    }
};