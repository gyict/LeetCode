class Solution {
public:
    int numDecodings(string s) {
        int len=s.length();
        if(len==0)return 0;
        int i;
        int* num=new int[len];
        for(i=0;i<len;i++) num[i]=0;
        if(s[0]=='0') return 0;
        num[0]=1;
        if(s[1]=='0'){
            if(s[0]=='1'||s[0]=='2') num[1]=1;
            else return 0;
        }
        else {
            if(((s[1]>='1' && s[1]<='6')&&(s[0]=='2'))||(s[0]=='1')) num[1]=2;
            else num[1]=1;
        } 
        for(i=2;i<len;i++){
            if(s[i]=='0'){
                if(s[i-1]=='1'||s[i-1]=='2')num[i]=num[i-2];
                else return 0;
            }
            else{
                if(((s[i-1]=='2')&&(s[i]>='1'&&s[i]<='6'))||(s[i-1]=='1')){
                    num[i]=num[i-1]+num[i-2];
                }
                else num[i]=num[i-1];
            }
        }
        return num[len-1];
    }
};