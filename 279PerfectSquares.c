class Solution {
public:
    int min(int a,int b){
        return a<b?a:b;
    }
    int numSquares(int n) {
        int i,k,tmp;
        int* dp = new int[n+1];
        dp[0]=1;
        for(i=1;i<n+1;i++) dp[i]=i;
        for(i=1;i*i<=n;i++) dp[i*i]=1;
        for(i=0;i<=n;i++){
            for(k=1;k*k+i<=n;k++){
                dp[k*k+i]=min(dp[k*k+i],dp[i]+1); //recursive
            }
            
        }
        return dp[n];
    }
};