class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ele;
        int n=nums.size();
        if(n==0) return ele;
        if(n==1) {
            ele.push_back(nums[0]);
            return ele;
        }
        int num1,num2,count1=0,count2=0,i;
        num1=0;
        num2=0;
        for(i=0;i<n;i++){           //look for num1 and num2
            if(num1==nums[i]) count1++;
            else if(num2==nums[i]) count2++;
            else if(count1==0) {
                num1=nums[i];
                count1++;
            }
            else if(count2==0) {
                num2=nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
            
        }
        count1=0;
        count2=0;
        for(i=0;i<n;i++){
            if(num1==nums[i]) count1++;
            else if(num2==nums[i]) count2++;
        }
        if(count1>n/3) ele.push_back(num1);
        if((count2>n/3)&&(num1!=num2)) ele.push_back(num2);
        return ele;
    }
};