DC Version:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max;
        if(nums.size()==1) return nums[0];
        max=findMaxSub(nums,0,nums.size()-1);
        return max;
    }
    
    int largest(int x,int y,int z){
        int tmp=x>y?x:y;
        return tmp>z?tmp:z;
    }
    
    int findMaxCross(vector<int>& a,int low,int mid,int high){
        int leftsum=-9999,rightsum=-9999,sum=0;
        int i;
        if((low==mid)&&(mid==high)) return a[low];
        for(i=mid;i>=low;i--){
            sum=sum+a[i];
            if(sum>leftsum){
                leftsum=sum;
            } 
        }
        //cout<<"left"<<leftsum;
        sum=0;
        //if(mid==high) return a[mid];
        for(i=mid+1;i<=high;i++){
            sum=sum+a[i];
            if(sum>rightsum){
                rightsum=sum;
            } 
        }
        //cout<<"right"<<rightsum;
        if(leftsum<0&&rightsum<0){
            return leftsum>rightsum?leftsum:rightsum;
        }
        return leftsum+rightsum;
    }
    
    int findMaxSub(vector<int>& a,int low,int high){
        int leftsum,rightsum,crosssum;
        if(low==high) return a[low];
        else {
            int mid=(low+high)/2;
            leftsum=findMaxSub(a,low,mid);
            rightsum=findMaxSub(a,mid+1,high);
            crosssum=findMaxCross(a,low,mid,high);
        }
       // cout<<"left"<<leftsum<<"right"<<rightsum<<"cross"<<crosssum<<endl;
        return largest(leftsum,rightsum,crosssum);
    }
};



DP Version:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max=nums[0],sum=nums[0];
        int j;
        for(j=1;j<n;j++){
            if(sum<0) sum=0;
            sum+=nums[j];   //make sure it's a sequence
            max=more(sum,max);
        }
        return max;
    }
    
    int more(int x,int y){
        return x>y?x:y;
    }
};