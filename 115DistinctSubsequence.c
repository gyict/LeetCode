class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        if(m==0||n==0)return 0;
        vector<vector<int> >path ((m+1),vector<int>(n+1,0));
        int i,j;
        for(i=0;i<=m;i++){
            path[i][0]=1;
        }
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    path[i][j]=path[i-1][j]+path[i-1][j-1];
                }
                else path[i][j]=path[i-1][j];
            }
        }
        return path[m][n];
    }
};