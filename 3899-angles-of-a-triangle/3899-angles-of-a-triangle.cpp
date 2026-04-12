class Solution {
    bool triangle_possible(vector<int>& sides){
        return (sides[0] + sides[1] > sides[2] && sides[0] + sides[2] > sides[1] && sides[2] + sides[1] > sides[0]);
    }
    double angles(double a, double b, double c){
        double angle = (b*b + c*c - a*a)/(2*b*c);
        double pi = 2*acos(0.0);
        return acos(angle)*(180/pi);
    }
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> ans(3);
        if(triangle_possible(sides)){
            ans[0] = angles(sides[0],sides[1],sides[2]);
            ans[1] = angles(sides[1],sides[2],sides[0]);
            ans[2] = angles(sides[2],sides[0],sides[1]);
            sort(ans.begin(),ans.end());
            return ans;
        }
        else return {};
    }
};