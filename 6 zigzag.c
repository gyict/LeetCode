class Solution {
public:
    string convert(string s, int numRows) {
        if((numRows==0)||(numRows==1)) return s;
        string res="";
        int i,j=0,len,k=0,sum=0,col;
        len=s.length();
        //printf("len:%d",len);
        col=len/(2*(numRows-1))+1;
        
        for(i=0;i<numRows;i++){     //rows
            for(j=0;j<col;j++){
                if((i==0)||(i==numRows-1)){
                    if(i+2*(numRows-1)*j<len){
                        res+=s[i+2*(numRows-1)*j];
                        k++;
                        //cout<<i+2*(numRows-1)*j<<" "<<"one"<<" ";
                    }
                }
                else{
                    //sum=2*(numRows-1)*(j+1);
                    if(i+2*(numRows-1)*j<len){
                        sum=2*(numRows-1)*(2*j+1);
                        res+=s[i+2*(numRows-1)*j];
                        k++;
                        //cout<<i+2*(numRows-1)*j<<" "<<"two"<<" ";
                    }
                    if(k<len) {
                        int t=sum-i-2*(numRows-1)*j;
                        if((t<len)&&(t>0)&&(t>sum-t)){
                            res+=s[t];
                            k++;
                            //cout<<t<<" "<<"three"<<" ";
                        }
                    }
                }
            }
        }
        
        return res;
    }
};