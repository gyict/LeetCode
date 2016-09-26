class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        int i,prev;
        int* opt = new int[n+1];
        opt[0]=0;
        opt[1]=nums[0];
        for(i=2;i<n+1;i++){
            prev=opt[i-2]+nums[i-1];
            opt[i]=prev>opt[i-1]?prev:opt[i-1];
        }
        return opt[n];
    }
};


//213.House Robber II
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        //if(n==2)
        int i,prev,prev2;
        int* opt = new int[n];  //choose the first one
        int* opt2=new int[n];   //choose the last one 
        opt[0]=0;
        opt[1]=nums[0];
        for(i=2;i<n;i++){
            prev=opt[i-2]+nums[i-1];
            opt[i]=prev>opt[i-1]?prev:opt[i-1];
        }
        opt2[0]=0;
        opt2[1]=nums[1];
        for(i=2;i<n;i++){
            prev=opt2[i-2]+nums[i];
            opt2[i]=prev>opt2[i-1]?prev:opt2[i-1];
        }
        return opt[n-1]>opt2[n-1]?opt[n-1]:opt2[n-1];
    }
};