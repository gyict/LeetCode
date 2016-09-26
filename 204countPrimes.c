class Solution {
public:
    int countPrimes(int n) {
        if(n==0)return 0;
        int count=0;
        bool* isPrime = new bool[n];
        memset(isPrime,true,n);
        int i,k;
        for(i=2;i*i<n;i++){
            if(isPrime[i]){
                for(k=i;i*k<n;k++){
                    isPrime[i*k]=false;
                }
            }
        }
        for(i=2;i<n;i++){
            if(isPrime[i]) count++;
        }
        return count;
    }
};