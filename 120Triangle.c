class Solution {
public:
    int min(int x,int y){
        return x<y?x:y;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        if(row==1) return triangle[0][0];
        int* d = new int[row];
        int i,j;
        for(i=0;i<row;i++){
            d[i]=triangle[row-1][i];
        }
        for(j=row-2;j>=0;j--){
            for(i=0;i<=j;i++){
                d[i]=min(d[i]+triangle[j][i],d[i+1]+triangle[j][i]);
            }
        }
        return d[0];
    }
};


//multiuse:
class Solution {
public:
    int min(int x,int y){
        return x<y?x:y;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        if(row==1) return triangle[0][0];
        int** opt =new int*[2];
        opt[0]=new int[row];
        opt[1]=new int[row];
        int i,j;
        for(i=0;i<row;i++){
            opt[(row-1)%2][i]=triangle[row-1][i];
        }
        for(i=row-2;i>=0;i--){
            for(j=0;j<=i;j++){
                opt[i%2][j]=min(opt[(i+1)%2][j],opt[(i+1)%2][j+1])+triangle[i][j];
            }
        }
        return opt[0][0];
    }
};