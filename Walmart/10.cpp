class Solution {
public:
    
    double r,x,y;
    
    Solution(double radius, double x_center, double y_center) {
        r=radius,x=x_center,y=y_center;
    }
    
    vector<double> randPoint() {
        double p=(double)rand()/RAND_MAX;
        p=sqrt(p)*r;
        double theta=(double)rand()/RAND_MAX;
        theta*=360.0;
        return {x+p*cos(theta),y+p*sin(theta)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
