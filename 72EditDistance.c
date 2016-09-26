class Solution {
public:
    int min(int x,int y,int z){
        int tmp;
        tmp=x<y?x:y;
        return tmp<z?tmp:z;
    }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        if(m==0)return n;
        if(n==0)return m;
        vector<vector<int> >ed((m+1),vector<int>(n+1,0));
        int i,j;
        for(i=0;i<m+1;i++)ed[i][0]=i;
        for(j=1;j<n+1;j++)ed[0][j]=j;
        for(i=1;i<m+1;i++){
            for(j=1;j<n+1;j++){
                if(word1[i-1]==word2[j-1]){
                    ed[i][j]=ed[i-1][j-1];
                }
                else ed[i][j]=min(ed[i-1][j-1],ed[i-1][j],ed[i][j-1])+1;
            }
        }
        return ed[m][n];
    }
};