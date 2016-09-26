mine:runtimeerror

class Solution {

public:
    int min(int a,int b,int c){
        int temp;
        temp = a<b ? a:b;
        return temp<c? temp:c;
    }
    int nthUglyNumber(int n) {
        int* uglynub = new int[n];
        memset(uglynub,0,sizeof(int)*n);
        int i=0,mini;
        uglynub[0]=1;
        int index2=0,index3=0,index5=0;
        int twice=2*uglynub[0],third=3*uglynub[0],fifth=5*uglynub[0];
        while(i<=n){
            
            mini=min(twice,third,fifth);
            //i=i+1;
            if(mini==twice){
                twice = 2 * uglynub[++index2];
            }
            else{
                if(mini==third){
                   third = 3 * uglynub[++index3];
                }
                else{
                    fifth = 5 * uglynub[++index5];
                }
            }
            i++;
            uglynub[i]=mini;
        }
        return uglynub[n-1];
    }
};


accepted:
    //求三个数的最小值
    int min(int a, int b, int c){
        int minNum = a > b ? b : a;
        return minNum > c ? c : minNum;
    }
    //求第N个丑数
    int nthUglyNumber(int n) {
        int *ugly = new int[n];
        memset(ugly, 0, sizeof(int) * n);
        ugly[0] = 1;

        int factor2 = 2, factor3 = 3, factor5 = 5;
        int index2, index3, index5;
        index2 = index3 = index5 = 0;

        for(int i=1; i<n; i++){
            int minNum = min(factor2, factor3, factor5);
            ugly[i] = minNum;

            if(factor2 == minNum)
                 factor2 = 2 * ugly[++index2];
            if(factor3 == minNum)
                 factor3 = 3 * ugly[++index3];
            if(factor5 == minNum)
                 factor5 = 5 * ugly[++index5];
        }

        return ugly[n-1];
    }