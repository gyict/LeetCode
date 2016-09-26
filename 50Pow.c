class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n==1) return x;
        if(x==1) return 1;
        if((x<0)&&(n%2==0)) return myPow(-x,n);
        if((x<0)&&(n%2==1)) return -myPow(-x,n);
        if((x<0.0001)&&(n>=2)) return 0.0000;
        if(n<0) return myPow(1/x,-n);
        double tmp=myPow(x,n/2)*myPow(x,n-n/2);
        //if(tmp<0.00001) return 0.0000;
        return tmp;
        
    }
};


double my_pow(double x, int n)
{
    if(n==0)
            return 1.0;
    if(n<0)
        return 1.0 / pow(x,-n);
    double ans = 1.0 ;
    for(; n>0; x *= x, n>>=1)
    {
        if(n&1>0)
            ans *= x;
    }
    return ans;
}