class Solution {
public:
    double abs(double a){
        if(a>0) return a;
        else return -a;
    }
    int mySqrt(int x) {
        if(x==0) return 0;
        double x0=1;
        double x1=(x0*x0+x)/(2*x0); //nex x
        while(abs(x1*x1-x)>=0.001){
            x0=x1;
            //x1=(x0*x0+x)/(2*x0); 
            x1=x0/2+x/(2*x0);
        }
        return (int)x1;
    }
};