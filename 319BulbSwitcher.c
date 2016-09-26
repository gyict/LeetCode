//Time Exceeded
class Solution {
public:
    int bulbSwitch(int n) {
        int i,k=1,j;
        if(n==0) return 0;
        bool* bulb=new bool[n];
        memset(bulb,true,sizeof(bool)*n); //first round
        for(i=2;i<(n+1);i++){    //second to n round
            k=1;
            while(i*k<(n+1)){
                bulb[i*k-1]=!bulb[i*k-1];
                k++;
            }
          /*  cout<<i<<":";
             for(j=0;j<n;j++){
                cout<<bulb[j]<<"  ";
                //if(bulb[i]==true) count++;
            }
            cout<<endl;*/
        }
        int count=0;
        for(i=0;i<n;i++){
          //  cout<<bulb[i]<<"  ";
            if(bulb[i]==true) count++;
        }
      /*  for(i=n/2;i<n;i++){
            if(bulb[i]==false) count++;
        }*/
        return count;
    }
};

class Solution {
public:
    int bulbSwitch(int n) {
        int count;
        for(count=1;count*count<=n;count++);
        return count-1;
    }
};