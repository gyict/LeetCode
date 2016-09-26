class NumArray {
    private :vector<int> acc;
    private :int k,tmp=0;
public:
    NumArray(vector<int> &nums) {  //construct function
        for(k=0;k<nums.size();k++){
            tmp=tmp+nums[k];
            acc.push_back(tmp);
        }
        
    }
    
    int sumRange(int i, int j) {
        int sum=0;
        sum=acc[j]-acc[i-1];
        
        return sum;
        
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);