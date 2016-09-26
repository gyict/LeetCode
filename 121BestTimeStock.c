class Solution {
public:
    int max(int x,int y){
        return x>y?x:y;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        //if(n==1) return 0;
        int min=prices[0];
        int* bp=new int[n];
        int i;
        bp[0]=0;
        for(i=1;i<n;i++){
            if(prices[i]<min) min=prices[i];
            bp[i]=max(bp[i-1],prices[i]-min);
        }
        return bp[n-1];
    }
};

//122 II Multi-transactions
class Solution {
public:
    int max(int x,int y){
        return x>y?x:y;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)return 0;
        int pro=0,i;
        for(i=1;i<n;i++){
            if(prices[i]-prices[i-1]>0) pro+=prices[i]-prices[i-1];
        }
        return pro;
    }
};

//123 III 2-transactions
class Solution {
public:
    int max(int x,int y){
        return x>y?x:y;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        int* mp=new int[n];
        int* rmp=new int[n];
        int i,min=prices[0],maxs=prices[n-1];
        mp[0]=0;
        rmp[n-1]=0;
        for(i=1;i<n;i++){
            if(prices[i]<min){
                min=prices[i];
            }
            mp[i]=max(prices[i]-min,mp[i-1]);
        }
        for(i=n-2;i>=0;i--){
            if(prices[i]>maxs) maxs=prices[i];
            rmp[i]=max(rmp[i+1],maxs-prices[i]);
        }
        int sum=0;
        for(i=0;i<n;i++) sum=max(sum,mp[i]+rmp[i]);
        return sum;
    }
}; 