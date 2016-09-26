class Solution {
public:
    int arr[210][210];
    
    int min(int m,int n){
        return m<n?m:n;
    }
    int c(int a,int b){ //c(a,b)
        if(a<b) {
            arr[a][b]=0;
            return arr[a][b];
        }
        if(b==1) {
            arr[a][b]=a;
            return arr[a][b];
        }
        if((b==0)||(a==b)){
            arr[a][b]=1;
            return arr[a][b];
        } 
        if((arr[a-1][b]!=-1)&&(arr[a-1][b-1]!=-1)) {
            arr[a][b]=arr[a-1][b]+arr[a-1][b-1];
            return arr[a][b];
        }
        return c(a-1,b)+c(a-1,b-1);
    }
    int uniquePaths(int m, int n) {
        memset(arr,-1,sizeof(arr));
        //if(m==n) return 1;
        if((m==0)||(n==0)) return 0;
        int k=min(m,n);
        return c(m+n-2,k-1);
    }
};



//63 uniquePathsII With Obstacles
class Solution {
public:
    int arr[210][210];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();  //row
        int n=obstacleGrid[0].size(); //colomn
        memset(arr,0,sizeof(arr));
        int total;
        int i,j,k;
        for(j=0;j<n;j++){
            if(obstacleGrid[0][j]==1) 
                break;
            else arr[0][j]=1;
        }
        while(j<n) {
            arr[0][j]=0;
            j++;
        }
        for(i=0;i<m;i++){
            if(obstacleGrid[i][0]==1) 
                break;
            else arr[i][0]=1;
        }
        while(i<m){
            arr[i][0]=0;
            i++;
        }
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                if(obstacleGrid[i][j]==1) arr[i][j]=0;
                else{
                    arr[i][j]=arr[i-1][j]+arr[i][j-1];
                }
            }
        }
        return arr[m-1][n-1];
    }
};