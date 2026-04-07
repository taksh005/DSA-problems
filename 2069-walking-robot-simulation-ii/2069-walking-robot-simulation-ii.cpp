class Robot {
    vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    int x;
    int y;
    int width;
    int height;
    vector<string> dirNames = {"East","North","West","South"};
    int dir;
public:
    Robot(int width, int height) {
            dir = 0;
            x = 0;
            y = 0;
            this->width = width;
            this->height = height;
    }
    
    void step(int num) {
        int perimeter = 2 * (width - 1) + 2 * (height - 1);
        num%=perimeter;
        if(num==0){
            if(x==0&&y==0) dir = 3;
            return;
        }
        while(num>0){
            int dx = x + directions[dir].first;
            int dy = y + directions[dir].second;
            if(dx < width && dx>=0 && dy >=0 && dy < height){
                x = dx;
                y = dy;num--;
            }else{
                dir = (dir+1)%4;
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return dirNames[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */