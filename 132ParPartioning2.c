class Solution {
public:
    int min(int a,int b){
        return a<b?a:b;
    }
    int minCut(string s) {
        int len= s.length();
        int* minncut=new int[len+1];
        int i,j;
        for(i=0;i<=len;i++){
            minncut[i]=len-i;
        }
        bool** ispar=new bool*[len];
        for(i=0;i<len;i++){
            ispar[i]=new bool[len];
            memset(ispar[i],false,sizeof(bool)*len);
            // memset(matrix[i], false, sizeof(bool)*len);  
        }
        for(i=len-1;i>=0;i--){
            for(j=i;j<len;j++){
                if((s[i]==s[j])&&(j-i<2||ispar[i+1][j-1])){
                    ispar[i][j]=true;
                    minncut[i]=min(minncut[i],minncut[j+1]+1);
                }
            }
        }
        return minncut[0]-1;
    }
 /*   int minCut(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = s.size();
        int* dp = new int[len+1];
        for(int i=len; i>=0; i--)
            dp[i] = len-i;
        bool** matrix = new bool*[len];
        for(int i=0; i<len; i++)
        {
            matrix[i] = new bool[len];
            memset(matrix[i], false, sizeof(bool)*len);
        }
        for(int i=len-1; i>=0; i--)
            for(int j=i; j<len; j++)
            {
                if(s[i] == s[j] && (j-i<2 || matrix[i+1][j-1]))
                {
                    matrix[i][j] = true;
                    dp[i] = min(dp[i], dp[j+1]+1);
                }
            }
        return dp[0]-1;
    }*/
};

